 // CLASS: ARRIVAL
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //




#pragma once

#include "Event.h"

class Arrival : public Event
{
    public:
        Arrival(int theTime, Process *theProcess, Simulation* sim);
        void handleEvent();

};

