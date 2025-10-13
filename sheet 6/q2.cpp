#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class circularlink{
    node* head;
    node* tail;
    public:
    circularlink(){
        head = NULL;
        tail = NULL;
    }
    void push(int val,int pos){
        node* newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            if(pos==0){
            newnode->next = head;
            head = newnode;
            tail->next = head;
            }
            else{
            node* temp = head;
            for(int i=1;i<pos;i++){
                temp = temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            }
        }
    }
    void display(){
        if(head == NULL) return;
        node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<temp->data<<endl;
    }
};
int main() {
     circularlink cl;
    cl.push(1,0);
    cl.push(2,1);
    cl.push(3,2);
    cl.push(4,3);
    cl.display();
}
