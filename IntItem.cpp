 // CLASS: IntItem
     //
     // Author: MD JIDANUR RAHMAN,7895504
     //
     // REMARKS: storing int items in queue by extending list items
     //

#include "IntItem.h"

IntItem::IntItem()
{
    data = 0;
}

IntItem::IntItem(int i)
{
    data = i;
}



int IntItem::getData(){

    return data;
}



int IntItem::compareTo(ListItem* other){

    IntItem* item = dynamic_cast<IntItem* >(other);


    if(item){

        if(data > item->getData()){
            return 1;
        }
        else{
            return -1;
        }

    }

    return 0;


}

void IntItem::print(){}

