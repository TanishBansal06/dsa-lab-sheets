#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val; 
        next = NULL;
    }
};
class list {
public:
    Node *head;
    Node *tail;

    list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    Node* getHead() {
        return head;
    }
};
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next;   
    }
    return slow;
}
int main() {
    list l;
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    Node* middle = findMiddle(l.getHead());
    if (middle != NULL) {
        cout << "The middle element is " << middle->data << endl;
    }
}
