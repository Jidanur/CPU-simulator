 // CLASS: IntItem
     //
     // Author: MD JIDANUR RAHMAN,7895504
     //
     // REMARKS: storing int items in queue by extending list items
     //

#pragma once
#include "ListItem.h"


class IntItem : public ListItem
{
    public:
        //constructors
        IntItem();
        IntItem(int i);

        //return int
        int getData();

        //compares integers
        int compareTo(ListItem *other);

        //prints the stored int
        void print();

    private:
        int data;
};
