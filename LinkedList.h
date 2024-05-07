#include <iostream>
using namespace std;

struct Node
{
    int data; 
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList 
{

private:
    Node* head; //head node

public:

    LinkedList(); //public functions
    ~LinkedList();
    void insert(int val);
    void printLinkedList();
};
