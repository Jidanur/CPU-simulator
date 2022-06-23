 // CLASS: priority queue
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     // keeps the items sorted in queue


#include "PriorityQueue.h"
#include"Node.h"
#include"ListItem.h"


PriorityQueue::PriorityQueue()
{
    head = nullptr;
    tail =nullptr;
    size = 0;
}



bool PriorityQueue::isEmpty(){

    return size==0;

}

int PriorityQueue::getSize(){

    return size;
}


void PriorityQueue::insert(ListItem *item){

    // if q is empty
    if(isEmpty()){

        head = new Node(item,nullptr);
        tail = head;
    }

    // if new item is smaller than front item
    else if (head->getItem()->compareTo(item) == 1){
        Node *newNode = new Node(item,head);
        head = newNode;

    }
    // if new item is bigger than last item
    else if(tail->getItem()->compareTo(item) == -1){
        Node *newNode = new Node(item,nullptr);
        tail->setNext(newNode);
        tail = newNode;
    }


    // else somewhere in middle
    else{

        Node *prev = nullptr;
        Node *curr = head;
        bool stop = false;



        while(curr!=nullptr && !stop){

            //if current item bigger than new item
            if(curr->getItem()->compareTo(item)== 1){
                stop = true;
            }
            else{
                prev = curr;
                curr = curr->getNext();
            }

        }


        if(prev){
            if(curr){
                prev->setNext(new Node(item,curr));
            }
            else{
                Node *newNode = new Node(item,nullptr);
                prev->setNext(newNode);

            }
        }

    }

    size++;


}


ListItem* PriorityQueue::dequeue(){

    ListItem *deq = nullptr;

    if(!isEmpty()){
        deq = head->getItem();
        head = head->getNext();
        size--;
    }

    return deq;

}


void PriorityQueue::print(){


    Node *curr = head;

    while(curr){
        curr->getItem()->print();
        curr = curr->getNext();
    }

}

















