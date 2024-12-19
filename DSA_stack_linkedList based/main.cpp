#include <iostream>

using namespace std;

class StackNode{
public:
    int data;
    StackNode * prev;
    StackNode(int _data){
        data = _data;
        prev =NULL;
    }
};

class StackLinkedList{
public:
    StackNode *top;
    StackLinkedList(){
        top = NULL;
    }

    void push(int data){
        StackNode *newNode = new StackNode(data);
        if(top == NULL){
            top=newNode;
        }
        else{
            newNode->prev = top;
            top=newNode;
        }
    }

    int pop(){
        if(top == NULL){
            //stack is empty
            throw "Stack is empty";
        }
        int data = top->data;
        StackNode *temp = top;
        top = top->prev;
        delete temp;
        return data;

    }

    void displayContent(){
        StackNode *curr = top;
        while(curr!=NULL){
            cout<<curr->data<<"-->";
            curr=curr->prev;
        }
        cout<<endl;

    }
};





int main()
{

    //Add Node --> Push
    //Remove and Display Node --> Pop
    //Display last node --> Peek
    cout<<"Stack"<<endl;
    StackLinkedList l;
    l.push(30);
    l.push(40);
    l.push(87);
    l.push(98);
    l.displayContent();
    try {
        cout << l.pop() << "-->";
        cout << l.pop() << "-->";
        cout << l.pop() << "-->";
        cout << l.pop();
        cout << l.pop();
    } catch (const char* msg){
        cout<<"\n"<<msg<<endl;
    }
    return 0;
}
