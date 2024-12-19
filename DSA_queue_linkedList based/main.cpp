#include <iostream>

using namespace std;

class NodeQueue{
public:
    int data;
    NodeQueue *next;
    NodeQueue(int _data){
        data=_data;
        next=NULL;
    }
};

class QueueLinkedList{
public:
    NodeQueue *front;
    NodeQueue *rear;

    QueueLinkedList(){
        rear=front=NULL;
    }

    void enqueue(int data){
        NodeQueue * newNode = new NodeQueue(data);
        if(front == NULL){//empty queue
            rear = front = newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }

    int dequeue(){
        if(front == NULL){
            throw "Queue is Empty";
        }
        NodeQueue  *temp = front;
        int data = front->data;
        front=front->next;
        delete temp;
        return data;
    }
};


int main() {
    cout<<"Linear Queue using linked list"<<endl;
    QueueLinkedList l;
    l.enqueue(50);
    l.enqueue(70);
    l.enqueue(90);
    try {
        cout << l.dequeue() << "\t";
        cout << l.dequeue() << "\t";
        cout << l.dequeue() << "\t";
        cout << l.dequeue() << "\t";
    }
    catch (const char *msg) {
        cout <<"\n"<< msg << endl;
    }
    l.enqueue(50);
    l.enqueue(70);
    l.enqueue(90);
    return 0;
}

