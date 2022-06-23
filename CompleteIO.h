 // CLASS: COMPLETE IO
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //

#pragma once

#include "Event.h"


class CompleteIO : public Event
{
    public:
        CompleteIO(int theTime, Process *theProcess, Simulation* sim);

        void handleEvent();


};
