 // CLASS: EVENT
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     //

#include "Event.h"
#include"Arrival.h"
#include"Timeout.h"
#include"Process.h"

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	 :eventTime(theTime), process(theProcess), sim (theSim) {}



int Event::getTime(){
    return eventTime;
    }


Process* Event::getProcess(){
    return process;
    }


int Event::compareTo(ListItem *other){

    Event* compare = dynamic_cast<Event *>(other);

    if(compare){



        if(eventTime > compare->getTime()){
            return 1;
        }
        else if(eventTime == compare->getTime()){
                //if equal time


                //if newevent is timeout and this is arrival then this one is smaller
            if((dynamic_cast<Arrival *>(this))&& (dynamic_cast<Timeout *>(compare))){
                return -1;
            }

            //if new Item is arrival and this one is timeout then this one is bigger
            else if((dynamic_cast<Arrival *>(compare))&& (dynamic_cast<Timeout *>(this))){
                return 1;
            }


            //else compare with process ID
            else{
                return process->compareTo(compare->getProcess());
            }
        }
        else{
            return -1;
        }
    }


	return 0;
}

void Event::print(){

    cout<<eventTime<<endl;

}

