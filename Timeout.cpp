 // CLASS: TIMEOUT
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //

#include "Timeout.h"
#include"Simulation.h"
#include"Process.h"
#include"StartCPU.h"

Timeout::Timeout(int theTime, Process *theProcess, Simulation* sim):Event(theTime,theProcess,sim){}



void Timeout::handleEvent(){

    sim->setCPUstatus(false);

    Process* tempProcess = getProcess();
    tempProcess->lastActive(getTime()); //SETS THE TIME WHEN IT LEAVES THE CPU

    sim->addCPUqueue(tempProcess); //ADDS THE PROCESS TO CPU QUEUE FOR ANOTHER ROUND

    cout <<"Time "<<getTime() <<": Process "<< tempProcess->getID()<< " times out (needs "<< tempProcess->getCurrentCPU()<< " units more)."<<endl;


    //IF ANY PROCESS STILL WAITING TO PROCESS IN QUEUE SCHEDULE A STARTCPU FOR THAT

    Process* next = sim->CPUqueue();

    if(next){
        sim->addEvent(new StartCPU(getTime(),next,sim));
    }



}
