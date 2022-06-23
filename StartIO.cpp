 // CLASS: STARTIO
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //


#include "StartIO.h"
#include"Process.h"
#include"Simulation.h"
#include"CompleteIO.h"


StartIO::StartIO(int theTime, Process *theProcess, Simulation* sim):Event(theTime,theProcess,sim){}


void StartIO::handleEvent(){

    sim->setIOstatus(true); // SETING IO TO BUSY


    Process* tempProcess = getProcess();
    tempProcess->updateBursts(); // UPDATING PROCESS BURSTS
    int burstTime = tempProcess->getCurrentIO();  // GETS THE CURRENT BURST TIME FROM PROCESS
    int waitTime = getTime() - tempProcess->lastActive(); // CALCULATING WAIT TIME
    tempProcess->addWait(waitTime); // ADDING THE WAIT TIME


    cout<<"Time "<<getTime()<<": Process "<<tempProcess->getID() <<" begins I/O burst of length " <<burstTime <<endl;

    // SCHEDULE THE COMPLETE IO
    sim->addEvent(new CompleteIO((getTime()+burstTime),tempProcess,sim));


    //CHANGING THE CURRENT IO OF PROCESS
    tempProcess->setCurrentIO(0);



}
