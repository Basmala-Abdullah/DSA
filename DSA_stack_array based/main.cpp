#include <iostream>

using namespace std;


class Stack{
    int top;
    int size;
    int *items;
    static int noOfStacks;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        items = new int[size];
        noOfStacks++;
    }

    int push(int data){
        if(top == size-1){
            return 0;
        }
        top++;
        items[top]=data;

        return 1;
    }

    int pop(){

        if(top == -1){
            throw "Cannot pop, Stack is empty";
        }
        int data=items[top];
        top--;
        return data;
    }

    int isEmpty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int isFull(){
        if(top == size-1){
            return 1;
        }
        else{
            return 0;
        }
    }





    void viewContent(){
        for(int i=0;i<=top;i++){
            cout<<items[i]<<endl;
        }
    }



    void reverseStack(){
        int noOfitems = top+1;
        for(int i=0;i<noOfitems/2;i++){
            int temp = items[i];
            items[i]= items[noOfitems-i-1];
            items[noOfitems-i-1]=temp;
        }
    }

    ~Stack() {
        delete[] items;
        noOfStacks--;
    }



};


int Stack::noOfStacks = 0;

int main()
{
    cout << "Enter Size of the stack:" << endl;
    int size;
    cin>>size;


    Stack stack1(size);

    stack1.push(5);
    stack1.push(6);
    stack1.push(7);
/*
    try {
        stack1.pop();
        stack1.pop();
        stack1.pop();
        stack1.pop();
    } catch (const char* msg) {
        cout << msg<<endl;
    }
*/
    stack1.reverseStack();
    stack1.viewContent();


    return 0;
}
