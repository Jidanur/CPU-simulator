 // CLASS: PROCESS
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //


#include "Process.h"
#include <iostream>
using namespace std;


int Process:: UniqueID = 1;

Process::Process(int arrival,Queue* cpu, Queue* io){

    pID = UniqueID++;
    arrivalTime = arrival;
    lastActiveTime = arrival;
    cpuBursts = cpu;
    ioBursts = io;
    waitTime = 0;
    currentCPUburst = 0;
    currentIOburst = 0;

}


int Process:: getID(){
    return pID;
}

int Process::lastActive(){

return lastActiveTime;

}

int Process::getCurrentCPU(){

    return currentCPUburst;
}

int Process::getCurrentIO(){

    return currentIOburst;
}


void Process::setCurrentCPU(int time){

    currentCPUburst = time;
}

void Process::setCurrentIO(int time){

    currentIOburst = time;
}

void Process::lastActive(int time){

    lastActiveTime = time;

}



void Process::updateBursts(){

    if(!cpuBursts->isEmpty() && currentCPUburst == 0){
        IntItem *item = dynamic_cast<IntItem *>(cpuBursts->dequeue());

        if(item){
            currentCPUburst = item->getData();
        }
    }

    if(!ioBursts->isEmpty() && currentIOburst == 0){

        IntItem *item = dynamic_cast<IntItem* >(ioBursts->dequeue());

        if(item){
            currentIOburst = item->getData();
        }
    }


}


bool Process::hasCPUbursts(){

    return (!cpuBursts->isEmpty()) || currentCPUburst>0;

}


bool Process::hasIObursts(){

    return  (!ioBursts->isEmpty()) || currentIOburst>0;
}


void Process::addWait(int time){

    waitTime +=time;

}

int Process::compareTo(ListItem *other){

    Process* compare = dynamic_cast<Process *>(other);


    if(compare){
        if(pID > compare->getID()){
            return 1;
        }
        else{
            return -1;
        }

    }

    return 0;

}



void Process::exit(int time){

    exitTime = time;

}


void Process::print(){

    cout<< pID << "\t"<< arrivalTime << "\t" << exitTime << "\t" << waitTime <<endl;
}

