#Md Jidanur rahman
# student number - 7895504
# Assignment 2 / 2150


CC = clang++
CFLAGS = -Wall --std=c++11

OBJFILES = ListItem.o IntItem.o Node.o Queue.o PriorityQueue.o Event.o Arrival.o StartCPU.o StartIO.o Timeout.o CompleteCPU.o CompleteIO.o Exit.o Process.o Simulation.o


# this rule will build A2 as the executable from the object files
all: A2main.o $(OBJFILES)
	$(CC) $(CFLAGS) -o main $< $(OBJFILES)


#command for build the test
test: Tests.o $(OBJFILES)
	$(CC) $(CFLAGS) -o test $< $(OBJFILES)

# this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) 


clean:
	rm *.o main test