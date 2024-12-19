#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include "node.h"
using namespace std;
class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList();

    void add(int data);

    Node * getNodeUsingData(int data);

    void remove(int data);

    void display();


    void InsertAfter(int data,int afterData);

    void InsertBefore(int data, int beforeData);

    int GetCount();

    int GetDataByIndex(int index);

    int insertByIndex(int index ,int data);

    void mergeLinkedList(LinkedList& l);
};


#endif // LINKEDLIST_H_INCLUDED
