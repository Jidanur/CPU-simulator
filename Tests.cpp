#define CATCH_CONFIG_MAIN

#include"catch.hpp"

#include"PriorityQueue.h"
#include"ListItem.h"
#include"IntItem.h"
#include"Process.h"
#include"Arrival.h"

TEST_CASE("TESTING THE PRIORITYQUEUE CONSTRUTOR"){

    PriorityQueue *pq = new PriorityQueue();

    REQUIRE(pq != nullptr);
    REQUIRE(pq->getSize() == 0);



}



TEST_CASE("Testing isEmpty() function"){

    PriorityQueue *pq = new PriorityQueue();


    //Edge case
    REQUIRE(pq->isEmpty()== true);


    //inserting random listItems
    ListItem *a = new IntItem(5);
    ListItem *b =  new IntItem(7);
    ListItem *c = new IntItem(6);

    pq->insert(a);

    pq->insert(b);

    pq->insert(c);

    //testing
    REQUIRE(pq->isEmpty() == false);


}

TEST_CASE("TESTING getSize() Function"){


    PriorityQueue *pq = new PriorityQueue();

    //edge case
    REQUIRE(pq->getSize() == 0);

     //inserting random listItems
    pq->insert(new IntItem(5));

    pq->insert(new IntItem(7));

    pq->insert(new IntItem(6));


    REQUIRE(pq->getSize() == 3);

}


TEST_CASE("TESTING insert() function"){


    PriorityQueue *pq = new PriorityQueue();

     //inserting random listItems
    pq->insert(new IntItem(5));

    pq->insert(new IntItem(7));

    pq->insert(new IntItem(6));

    pq->insert(new Process(0,nullptr,nullptr));

    pq->insert(new Arrival(0,nullptr,nullptr));


    REQUIRE(pq->getSize() == 5);
    REQUIRE(pq->isEmpty() == false);


}



TEST_CASE("TESTING dequeue() Function"){

    PriorityQueue *pq = new PriorityQueue();

    //edge case
    REQUIRE(pq->dequeue() == nullptr);


    //inserting random listItems
    ListItem *a = new IntItem(5);
    ListItem *b =  new IntItem(7);
    ListItem *c = new IntItem(8);

    pq->insert(a);

    pq->insert(b);

    pq->insert(c);


    //testing
    REQUIRE(pq->dequeue() == a);
    REQUIRE(pq->getSize() == 2);

    REQUIRE(pq->dequeue() == b);
    REQUIRE(pq->getSize() == 1);

    REQUIRE(pq->dequeue() == c);


    //edge case
    REQUIRE(pq->getSize() == 0);
    REQUIRE(pq->isEmpty() == true);
    REQUIRE(pq->dequeue() == nullptr);

}



TEST_CASE("TESTING IF THE QUEUE IS SORTED"){

    PriorityQueue *pq = new PriorityQueue();




    //inserting random listItems in random order
    ListItem *a = new IntItem(50);
    ListItem *b =  new IntItem(7);
    ListItem *c = new IntItem(69);
    ListItem *d = new IntItem(49);
    ListItem *e =  new IntItem(25);
    ListItem *f = new IntItem(77);

    pq->insert(a);
    pq->insert(b);
    pq->insert(c);
    pq->insert(d);
    pq->insert(e);
    pq->insert(f);


    //first item should be the smallest
    REQUIRE(pq->dequeue() == b);

    REQUIRE(pq->dequeue() == e);

    REQUIRE(pq->dequeue()->compareTo(pq->dequeue()) == -1);

}







