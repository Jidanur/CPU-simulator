 // CLASS: ARRIVAL
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //



#include "Arrival.h"
#include"Process.h"
#include"Simulation.h"
#include"StartCPU.h"


Arrival::Arrival(int theTime, Process *theProcess, Simulation* sim): Event(theTime, theProcess, sim){}


void Arrival::handleEvent(){

    cout<< "Time  " <<getTime() << ": Process " <<getProcess()->getID() << " arrives in system:";


    // if CPU is not busy then schedule startCpu event in simulation
    if(!sim->isCPUbusy()){
        sim->addEvent(new StartCPU(getTime(),getProcess(),sim));
         cout<<" CPU is free (process begins execution)." <<endl;
    }

    // if cpu busy then put it in cpu queue
    else{
        sim->addCPUqueue(getProcess());
        cout<< " CPU is busy (process will be queued)."<<endl;
    }


    //reads the next process arrival
    sim->readProcess();

}
