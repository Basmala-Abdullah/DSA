#include <iostream>

using namespace std;


class QueueArray{

    int *items;
    int rear;
    int front;
    int maxSize;
    int currentSize;
public:
    QueueArray(int _size){
        items = new int[_size];
        currentSize=0;
        maxSize = _size;
        front = rear=-1;
    }



    int isEmpty(){
        if(currentSize==0){
            return 1;
        }
        return 0;
    }

    int isFull(){
        if(currentSize==maxSize){
            return 1;
        }

        return 0;
    }

    int enqueue(int data){
        if(isFull()){
            return 0;
        }
        if(isEmpty()){
            front=rear=0;
        }
        else if(rear== maxSize-1 && front !=0){
            rear=0;
        }else{
            rear++;
        }
        items[rear]=data;
        currentSize++;
        return 1;
    }

    int dequeue(){

        if(isEmpty()){
            throw "Queue is Empty";
        }
        int data = items[front];
        if(rear == front){
            //last element is returned
            front=rear=-1;
        }
        else if(front == maxSize-1){
            //circular queue
            front=0;
        }else{
            front++;
        }
        currentSize--;
        return data;
    }



};



int main() {
    cout<<"Circular Queue using array"<<endl;
    int data;
    QueueArray q(5);

    q.enqueue(10) ? cout << "Data Entered \n" : cout << "Failure\n";
    q.enqueue(20) ? cout << "Data Entered \n" : cout << "Failure\n";
    q.enqueue(30) ? cout << "Data Entered \n" : cout << "Failure\n";
    q.enqueue(40) ? cout << "Data Entered \n" : cout << "Failure\n";
    q.enqueue(50) ? cout << "Data Entered \n" : cout << "Failure\n";
    q.enqueue(60) ? cout << "Data Entered \n" : cout << "Failure\n";

    try {
        data = q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
    } catch (const char* msg) {
        cout << msg<<endl;
    }

    return 0;
}
