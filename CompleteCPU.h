 // CLASS: COMPLETE CPU
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //

#pragma once

#include "Event.h"

class CompleteCPU : public Event
{
    public:
        CompleteCPU(int theTime,Process *theProcess, Simulation* sim);
        void handleEvent();

};
