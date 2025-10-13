#include <iostream>
using namespace std;
class node {
public:
    char data;
    node* next;
    node* prev;
    node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class doublelink {
    node* head;
    node* tail;
public:
    doublelink() {
        head = NULL;
        tail = NULL;
    }
    void push(char val, int pos) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else {
            if (pos == 0) {
                newnode->next = head;
                newnode->prev = tail;
                head->prev = newnode;
                tail->next = newnode;
                head = newnode;
            }
            else {
                node* temp = head;
                for (int i = 1; i < pos; i++) {
                    temp = temp->next;
                }
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next->prev = newnode;
                temp->next = newnode;
                if (temp == tail) tail = newnode;
            }
        }
    }
    void display() {
        if (head == NULL) return;
        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    bool palindrome(){
        node* temp=head;
        node* temp2=tail;
        while(temp != temp2){
            if(temp->data != temp2->data){
                return false;
            }
            temp=temp->next;
            temp2=temp2->prev;
        }
        return true;
    }
};
int main() {
    doublelink c;
    c.push('l',0);
    c.push('e',1);
    c.push('v',2);
    c.push('e',3);
    c.push('l',4);
    c.display();
    cout<<c.palindrome()<<endl;
}
