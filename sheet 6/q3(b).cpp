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
    int size(){
        if(head == NULL) return -1;
        node* temp = head;
        int count=0;
        do{
            count++;
            temp = temp->next;
        }while(temp!=head);
        return count;
        cout<<endl;
    }
};
int main() {
     circularlink cl;
    cl.push(1,0);
    cl.push(2,1);
    cl.push(3,2);
    cl.push(4,3);
    cout<<cl.size();
}
