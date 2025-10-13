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
    void pop(int pos){
        if(head==NULL){
            return;
        }
        if(pos==0){
            node* temp = head;
            if(head == tail){
                head = tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
            }
            delete temp;
        }
        else{
             node* temp = head;
            for(int i=1;i<pos && temp->next!=head;i++){
                temp = temp->next;
            }
            node* del = temp->next;
            temp->next = del->next;
            if(del == tail) tail = temp;
            delete del;
        }
    }
    void display(){
        if(head == NULL) return;
        node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<endl;
    }
int search(int val) {
        if (head == NULL) return -1;
        node* temp = head;
        int pos = 0;
        do {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        } while (temp != head);
        return -1;
    }
};
int main() {
     circularlink cl;
    cl.push(1,0);
    cl.push(2,1);
    cl.push(3,2);
    cl.push(4,3);
    cl.display();
    cl.pop(0);
    cl.display();
    cl.pop(2);
    cl.display();
    int x = 3;
    int pos = cl.search(x);
    if(pos != -1)
        cout <<"value"<<x<<"position"<<pos<<endl;
    else
        cout <<"value"<<x<<"not found"<<endl;
}
