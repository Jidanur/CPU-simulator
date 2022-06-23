
 // CLASS: TIMEOUT
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //

#pragma once

#include "Event.h"


class Timeout:public Event
{
    public:
        Timeout(int theTime, Process *theProcess, Simulation* sim);
        void handleEvent();


};

