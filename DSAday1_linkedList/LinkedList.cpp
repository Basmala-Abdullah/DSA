#include "LinkedList.h"

LinkedList::LinkedList(){
        head=nullptr;
        tail=nullptr;
        length=0;
    }

void LinkedList::add(int data){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next = newNode;
            newNode->prev=tail;
            tail = newNode;

        }
        length++;

    }

Node * LinkedList::getNodeUsingData(int data){
        Node *current = head;
        while(current){
            if(current->data == data){
                return current;
            }
            current = current->next;
        }
        return current;
    }


void LinkedList:: remove(int data){
        Node* nodeRemoved = getNodeUsingData(data);
        if(!nodeRemoved){
            cout<<"No node of that value"<<endl;
            return;
        }
        if(nodeRemoved == head){
            head=head->next;
            if (head)
                head->prev=NULL;

        }else if(nodeRemoved == tail){
            tail=tail->prev;
            tail->next=NULL;
        }else{
            nodeRemoved->next->prev=nodeRemoved->prev;
            nodeRemoved->prev->next=nodeRemoved->next;
        }
        length--;
        delete nodeRemoved;
    }


void LinkedList::display(){

        Node *current = head;
        if(current == NULL){
            cout<<"Linked List is empty"<<endl;
            return;
        }
        while(current){
            cout<<current->data<<"  ";
            current= current->next;
        }
        cout<<endl;
    }

void LinkedList::InsertAfter(int data,int afterData){
        Node* curr=head;
        while(curr && curr->data!=afterData) {
            curr=curr->next;
        }

        if (curr){
            Node* newNode = new Node(data);
            newNode->next=curr->next;
            newNode->prev=curr;

            if (curr->next != nullptr) {
                curr->next->prev = newNode;
            }else{
                tail=newNode;
            }
            curr->next = newNode;
            length++;
        }else{
            cout<<"Node not found!"<<endl;
        }

    }


void LinkedList::InsertBefore(int data, int beforeData) {

        Node* curr=head;
        while(curr&& curr->data!=beforeData) {
            curr=curr->next;
        }

        if (curr){
            Node* newNode = new Node(data);
            newNode->next=curr;
            newNode->prev=curr->prev;

            if (curr->prev != nullptr) {
                curr->prev->next = newNode;
            }else{
                head=newNode;
            }
            curr->prev = newNode;
            length++;
        }else{
            cout<<"Node not found!"<<endl;
        }

    }

int LinkedList::GetCount() {
        return length;
    }


int LinkedList::GetDataByIndex(int index){
        if(length==0){
            cout<<"Linked List is empty"<<endl;
            return -1;
        }
        if(index>=length || index<0){
            cout<<"Index is out of range"<<endl;
            return -1;
        }

        Node *curr= head;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->data;
    }

