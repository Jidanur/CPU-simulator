 // CLASS: STARTIO
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //

#pragma once
#include "Event.h"


class StartIO : public Event
{
    public:
        StartIO(int theTime, Process *theProcess, Simulation* sim);
        void handleEvent();

};
