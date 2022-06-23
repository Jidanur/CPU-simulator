 // CLASS: COMPLETE CPU
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //
#include "CompleteCPU.h"
#include"Simulation.h"
#include"Process.h"
#include"StartCPU.h"
#include"StartIO.h"
#include"Exit.h"


CompleteCPU::CompleteCPU(int time,Process* p,Simulation* s):Event(time,p,s){}


void CompleteCPU:: handleEvent(){

    sim->setCPUstatus(false); // SETING CPU IS NOT BUSY

    Process *tempProcess = getProcess();
    tempProcess->lastActive(getTime()); // SETING THE LAST TIME WHEN THE PROCESS WAS ACTIVE IN CPU

    cout<<"Time "<<getTime()<<": Process "<<tempProcess->getID() <<" completes CPU burst";


    // PROCESS DOES NOT HAVE ANY IO OR CPU BURSTS IT WILL EXIT
    if(!tempProcess->hasCPUbursts() && !tempProcess->hasIObursts()){
            cout <<endl;
        sim->addEvent(new Exit(getTime(),tempProcess,sim));
    }



    // IF PROCESS HAS IO BURSTS TO PROCESS
    if(tempProcess->hasIObursts()){
        cout <<" Queueing for I/O. ";


        if(!sim->hasIO() && !sim->isIObusy()){
                cout<<"I/O free Starting I/O"<<endl;
            sim->addEvent(new StartIO(getTime(),tempProcess,sim));

        }
        else{
            cout<<endl;
            sim->addIOqueue(tempProcess);
        }

    }


    // start the next process in QUEUE
    if(sim->hasCPU()){
        Process* next = sim->CPUqueue();

        if(next){
            sim->addEvent(new StartCPU(getTime(),next,sim));
        }
    }



}
