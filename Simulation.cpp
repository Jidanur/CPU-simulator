 // CLASS: Simulation
     //
     // Author: MD JIDANUR RAHMAN, 7895504

#include"Simulation.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include"Event.h"
#include"Arrival.h"
#include"IntItem.h"
#include"Process.h"
#include<strings.h>
#include<string.h>
#include<cstring>
#include<sstream>
#include<stdlib.h>





// constructor
Simulation::Simulation(){
    cpu = new Queue();
    io = new Queue();
    eventList = new PriorityQueue();
    processList = new PriorityQueue();

    cpuBusy = false;
    ioBusy = false;


}



void Simulation::runSimulation(char* fileName){


    string line;
    file.open(fileName); // opens the file

    if(file){
        getline(file,line);
        stringstream cpuM(line);
        cpuM >> cpuMax; // sets cpu quantum

        //reads the 1st process and puts arrival in event
        readProcess();

        do{
            Event* currEvent = dynamic_cast<Event* >(eventList->dequeue());

            if(currEvent){
                currEvent->handleEvent();
            }


        }while(!eventList->isEmpty()); //while eventList is not empty

    }
    file.close();

}




// reads next process in line
void Simulation::readProcess(){

    string line;
    getline(file,line);

    // if line is not empty
    if(!line.empty()){

        Queue *cpu = new Queue();
        Queue *io = new Queue();

        stringstream ss(line);

        int arrival ;

        ss>> arrival;
        while (!ss.eof())
        {
            int num;
            ss >> num;


            if(num<0){
                    // if negative then its io
                    io->enqueue(new IntItem(abs(num)));
                }
            else{
                cpu->enqueue(new IntItem(num));
                }
        }

        //initializing the process
        Process* temp = new Process(arrival,cpu,io);

        //PUTING THE PROCESS IN PROCESSLIST
        processList->insert(temp);

        //PUTTING THE PROCESS ARRIVAL IN EVENTLIST
        addEvent(new Arrival(arrival,temp,this));

    }


}



void Simulation::summary(){


cout<<"Process\tArrival\tExit\tWait"<<endl;
cout<<"#\tTime\tTime\tTime"<<endl;
cout<<"======================================="<<endl;
processList->print();


}


void Simulation::addEvent(ListItem* newEvent){
    eventList->insert(newEvent);
}

void Simulation::addCPUqueue(ListItem* p){
    cpu->enqueue(p);
}

void Simulation::addIOqueue(ListItem* p){
    io->enqueue(p);
}


void Simulation::setCPUstatus(bool state){
    cpuBusy = state;
}

void Simulation::setIOstatus(bool state){
    ioBusy = state;
}


Process* Simulation::CPUqueue(){
    Process* temp = nullptr;

    if(!cpu->isEmpty()){
        ListItem* item = cpu->dequeue();
        temp = dynamic_cast<Process* >(item);
    }
    return temp;
}

Process* Simulation::IOqueue(){
    Process* temp = nullptr;

    if(!io->isEmpty()){
        ListItem* item = io->dequeue();
        temp = dynamic_cast<Process* >(item);
    }
    return temp;
}

bool Simulation::isCPUbusy(){
    return cpuBusy;
}

bool Simulation::isIObusy(){
    return ioBusy;
}

int Simulation::getCPUmax(){
    return cpuMax;
}

bool Simulation::hasCPU(){

return !cpu->isEmpty();

}

bool Simulation::hasIO(){

return !io->isEmpty();

}



