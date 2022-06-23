 // CLASS: priority queue
     //
     // Author: MD JIDANUR RAHMAN, 7895504
     //
     // keeps the items sorted in queue


#pragma once


class Node;
class ListItem;


class PriorityQueue
{
    public:
        PriorityQueue();
        bool isEmpty();
        void insert(ListItem *item);
        ListItem *dequeue();
        int getSize();
        void print();


    private:
        Node *head;
        Node *tail;
        int size;

};

