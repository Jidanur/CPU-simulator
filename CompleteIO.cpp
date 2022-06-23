 // CLASS: COMPLETE IO
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //

#include "CompleteIO.h"
#include"Simulation.h"
#include"Process.h"
#include"StartCPU.h"
#include"StartIO.h"
#include"Exit.h"

CompleteIO::CompleteIO(int theTime, Process *theProcess, Simulation* sim):Event(theTime,theProcess,sim){}




void CompleteIO::handleEvent(){

    sim->setIOstatus(false);// SETING IO IS NOT BUSY

    Process *tempProcess = getProcess();
    tempProcess->lastActive(getTime());// SETING THE LAST TIME WHEN THE PROCESS WAS ACTIVE IN CPU OR IO

    cout<<"Time "<<getTime()<<": Process "<<tempProcess->getID() <<" completes IO burst";


    // IF NO BURSTS LEFT IN PROCESS THEN EXIT
    if(!tempProcess->hasCPUbursts() && !tempProcess->hasIObursts()){
            cout<<endl;
        sim->addEvent(new Exit(getTime(),tempProcess,sim));
    }



    //IF MORE CPU BURST IN PROCESS
    if(tempProcess->hasCPUbursts()){
        cout <<" Queueing for CPU. ";



        if(!sim->hasCPU() && !sim->isCPUbusy()){
            cout<<"CPU IS FREE STARTING PROCESS" <<endl;
            sim->addEvent(new StartCPU(getTime(),tempProcess,sim));

        }

        else{
            cout<<endl;
            sim->addCPUqueue(tempProcess);
        }

    }



    // NEXT IO PROCESS IN QUEUE
    if(sim->hasIO()){
        Process* next = sim->IOqueue();

        if(next){
            sim->addEvent(new StartIO(getTime(),next,sim));
        }
    }

}
