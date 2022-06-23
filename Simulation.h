 // CLASS: Simulation
     //
     // Author: MD JIDANUR RAHMAN, 7895504

#pragma once
#include<iostream>
#include <fstream>
#include<string>




using namespace std;

class Queue;
class PriorityQueue;
class Process;
class ListItem;

class Simulation {
private:
	// you will need to add fields
        // including: Queues for CPU and IO, and priority queues for Events

    Queue *cpu; // CPU process queue
    Queue *io; // IO process queue
    PriorityQueue *eventList;  //event List
    PriorityQueue *processList; // process List


    ifstream file; //input file
    int cpuMax; // maxtime a process can take in cpu
    bool cpuBusy; // boolean to check if cpu is busy
    bool ioBusy; //boolean to check if io is busy

public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

	//reads the next line puts process arrival in eventList
	void readProcess();


    void addEvent(ListItem* newEvent); // adds event in pq
    void addCPUqueue(ListItem* p); //adds process in cpu queue
    void addIOqueue(ListItem* p); // adds process in io queue
    void setCPUstatus(bool state); // sets cpu bool
    void setIOstatus(bool state);// sets io bool



    bool hasCPU(); //checks if cpu queue is empty
    bool hasIO(); // check if io queue is empty

    Process* CPUqueue();// dequeue front process from CPU queue
    Process* IOqueue();// dequeue front process from IO queue
    int getCPUmax(); // return the max cpu quantum
    bool isCPUbusy(); // returns cpu bool
    bool isIObusy(); // returns io bool



};// class Simulation
