#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) //constructor
{
}

LinkedList::~LinkedList() //destructor
{
  while (head != nullptr)
  {
      Node* temp = head;
      head = head->next;
      delete temp;
  }
}

void LinkedList::insert(int val) //insert function
{
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void LinkedList::printLinkedList() //print function
{
  Node* temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
