 // CLASS: EXIT
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //


#include "Exit.h"
#include"Process.h"


Exit::Exit(int theTime, Process *theProcess, Simulation* sim):Event(theTime,theProcess,sim){}



void Exit::handleEvent(){


    Process *tempProcess = getProcess();
    tempProcess->exit(getTime()); // SAVING THE EXIT TIME IN PROCESS


    std::cout<<"Time " << getTime() << ": Process "<<tempProcess->getID() << " completed all bursts and exiting the system"<<std::endl;

}
