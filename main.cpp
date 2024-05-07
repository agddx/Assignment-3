#include “Queue.h”
#include “LinkedList.h”

int main()
{
  Queue<int> ints; //initializing the queue

  ints.push(1); //adding 10 integers to it
  ints.push(2);
  ints.push(3);
  ints.push(4);
  ints.push(5);
  ints.push(6);
  ints.push(7);
  ints.push(8);
  ints.push(9);
  ints.push(10);

  ints.print(); //print

}
