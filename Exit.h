 // CLASS: EXIT
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //

#pragma once

#include "Event.h"


class Exit : public Event{
    public:
        Exit(int theTime, Process *theProcess, Simulation* sim);
        void handleEvent();
};
