#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node* prev;
    node(int val) {
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
    void push(int val, int pos) {
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
    void pop(int pos) {
        if (head == NULL) return;
        if (pos == 0) {
            node* temp = head;
            if (head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            delete temp;
        }
        else {
            node* temp = head;
            for (int i = 1; i < pos && temp->next != head; i++) {
                temp = temp->next;
            }
            node* del = temp->next;
            temp->next = del->next;
            del->next->prev = temp;
            if (del == tail) tail = temp;
            delete del;
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
    doublelink c;
    c.push(1, 0);
    c.push(2, 1);
    c.push(3, 2);
    c.push(4, 3);
    c.display();
    c.pop(0);
    c.display();
    c.pop(2);
    c.display();
    int x = 3;
    int pos = c.search(x);
    if (pos != -1)
        cout<<"value"<<x<<"position"<<pos<<endl;
    else
        cout<<"value"<<x<<"found"<<endl;
}
