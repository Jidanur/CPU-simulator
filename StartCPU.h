 // CLASS: STARTCPU
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //


#pragma once
#include "Event.h"



class StartCPU : public Event{
public:
        StartCPU(int theTime, Process *theProcess, Simulation* sim);
        void handleEvent();

};
