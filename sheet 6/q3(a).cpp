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
    int size(){
      if (head == NULL) return -1;
        node* temp = head;
        int count=0;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
        cout << endl;
    }
};
int main() {
    doublelink c;
    c.push(1, 0);
    c.push(2, 1);
    c.push(3, 2);
    c.push(4, 3);
    cout<<c.size();
}
