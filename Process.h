 // CLASS: PROCESS
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //



#pragma once
#include "ListItem.h"
#include"Queue.h"
#include"IntItem.h"


class Queue;


class Process: public ListItem
{
   private:

       int pID;
       int arrivalTime;
       int waitTime;
       int exitTime;

       int lastActiveTime;

       Queue *cpuBursts;
       Queue *ioBursts;

       int currentCPUburst; // STORES FRONT CPU BURST FROM QUEUE
       int currentIOburst; // STORES FRONT IO BURST FROM QUEUE

   public:

    //UniqueID number for each process
    static int UniqueID;

    Process(int arrival,Queue* cpu, Queue* io);

    //RETURNS PROCESS ID
    int getID();

    //RETURNS LAST TIME IT WAS ACTIVE IN CPU OR IO
    int lastActive();

    //RETURNS THE CURRENT CPU BURST
    int getCurrentCPU();

    //RETURNS THE CURRENT IO BURST
    int getCurrentIO();

    int compareTo(ListItem *other);

    //CHECKS THE QUEUE IF IT HAS MORE CPU BURSTS LEFT
    bool hasCPUbursts();

    //CHECKS THE QUEUE IF IT HAS MORE IO BURSTS LEFT
    bool hasIObursts();


    // CHANGES THE CURRENT CPU BURST VALUE
    void setCurrentCPU(int time);

     // CHANGES THE CURRENT IO BURST VALUE
    void setCurrentIO(int time);

//CHANGES THE LAST ACTIVE TIME
    void lastActive(int time);

    // ADDS WAIT TIME
    void addWait(int time);

    //SETS THE EXIT TIME
    void exit(int time);

    // CHECKS THE CPU AND IO QUEUE UPDATES THE VARIABLES CURRENTCPU AND CURRENTIO
    void updateBursts();

    void print();

};


