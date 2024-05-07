#include <iostream>
#include <stdexcept>
using namespace std;

template<typename ItemType>
struct Node
{
  ItemType data;
  Node* nextPtr;
};

template<typename ItemType>
class Queue
{
private:  //private variables
  Node<ItemType>* headPtr;
  Node<ItemType>* tailPtr;
  int num_items;

public: //public functions
    Queue();
    ~Queue();
    void push(ItemType data);
    ItemType pop();
    ItemType front();
    int size();
    bool empty();
    void print();
    void move_to_rear();
    void insertion_sort();
};


template<typename ItemType>
Queue<ItemType>::Queue() //creating the constructor
{
  headPtr = nullptr;
  tailPtr = nullptr;
  num_items = 0;
}

template<typename ItemType>
Queue<ItemType>::~Queue() //creating the destructor
{
  for (Node<ItemType>* tempNode = headPtr; tempNode != nullptr; tempNode = tempNode->nextPtr)
  {
    delete tempNode;
  }
}

template<typename ItemType>
bool Queue<ItemType>::empty() //function the checks for an empty queue
{
  return (headPtr == nullptr);
}

template<typename ItemType>
void Queue<ItemType>::push(ItemType data) //function that adds or pushes a function to the end of the queue
{
  Node<ItemType>* newNode = new Node<ItemType>;
  newNode->data = data;
  newNode->nextPtr = nullptr;
  if (empty())
  {
    headPtr = newNode;
    tailPtr = newNode;
  }
  else
  {
    tailPtr->nextPtr = newNode;
    tailPtr = newNode;
  }
  num_items++;
}

template<typename ItemType>
ItemType Queue<ItemType>::pop() //function that removes the node from the front of the queue
{
  ItemType tempData;
  if (!empty())
  {
    tempData = headPtr->data;
    Node<ItemType>* tempNode = headPtr;
    headPtr = headPtr->nextPtr;
    delete tempNode;
    tempNode = nullptr;
    num_items--;
    return tempData;
    }
  else
  {
    throw runtime_error("Queue is null”);
  }
}

template<typename ItemType>
ItemType Queue<ItemType>::front() //function that returns the front of the queue
{
  if (!empty())
  {
    return headPtr->data;
  }
  else
  {
    throw runtime_error("Queue is null”);
  }
}

template<typename ItemType>
int Queue<ItemType>::size() //function that returns the size of the queue
{
  return num_items;
}

template<typename ItemType>
void Queue<ItemType>::print() //print function
{
  if (empty())
  {
    cout << "Queue is null”;
    return;
  }
  else
  {
    for (Node<ItemType>* tempNode = headPtr; tempNode != nullptr; tempNode = tempNode->nextPtr)
    {
      cout << tempNode->data << " ";
    }
  }
}

template<typename ItemType>
void Queue<ItemType>::move_to_rear() //function that moves the element at the front of the queue to the rear
{
  if (empty())
  {
    return;
  }
  else
  {
    ItemType tempData = pop();
    push(tempData);
    return;
  }
}

template <typename ItemType>
int Queue<ItemType>::linear_search(vector<string>& items, string target, int pos_last) //recursive function that finds the last occurrence of the target
{
if (pos_last == 0)
    return -1; 
if (target == items[pos_last])
  return pos_last; 
else
  return linear_search(items, target, pos_last - 1);
}

template <typename ItemType>
void Queue<ItemType>::insertion_sort() //function to sort a list
{
  int key;
  bool insertionNeeded = false;

  for (Node<ItemType>* tempPtr = headPtr; tempPtr != nullptr; tempPtr = tempPtr->nextPtr)
    {
    key = tempPtr->data;
    insertionNeeded = false;

  for (Node<ItemType>* i = tempPtr->nextPtr; i != nullptr; i = tempPtr->nextPtr)
    {
    if (key < i->data)
    {
      insertionNeeded = true;
    }

  if (insertionNeeded)
  {
    move_to_rear();
  }
  }
  }
}
