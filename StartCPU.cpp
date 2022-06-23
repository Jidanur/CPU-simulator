 // CLASS: STARTCPU
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //




#include "StartCPU.h"
#include"Process.h"
#include"CompleteCPU.h"
#include"Timeout.h"
#include"Simulation.h"

StartCPU::StartCPU(int theTime, Process *theProcess, Simulation* sim):Event(theTime,theProcess,sim)
{}


void StartCPU::handleEvent(){

    //sets cpu status to busy
    sim->setCPUstatus(true);

    Process *tempProcess = getProcess();
    tempProcess->updateBursts(); //updates the cpu bursts time
    int burstTime = tempProcess->getCurrentCPU(); //gets the current cpuburst
    int waitTime = getTime() - tempProcess->lastActive(); // calculate the wait time from lastTime when it left cpu or io
    tempProcess->addWait(waitTime); // adds up to total wait time


    cout <<"Time " <<getTime()<< ": Process " << tempProcess->getID()<< " begins CPU burst";

    //if burst is smaller than cpu quantum then just schedule a complete cpu event
    if(burstTime <= sim->getCPUmax()){

         cout<< " (will complete all "<< burstTime << " units )." <<endl;

        sim->addEvent(new CompleteCPU((getTime()+ burstTime),tempProcess,sim));

        tempProcess->setCurrentCPU(0);

    }
    //if burst is bigger than cpu quantum then just schedule a timeout cpu event
    else{

        cout <<" (will time out; needs "<< burstTime << " units total)." <<endl;


        //calculates the new Time after exhausting the cpu and stores the time in process
        int newTime =  burstTime - sim->getCPUmax();

        tempProcess->setCurrentCPU(newTime);

        sim->addEvent(new Timeout((getTime()+sim->getCPUmax()),getProcess(),sim));

    }



}
