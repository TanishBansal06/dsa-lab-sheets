#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};
Node* reverseInGroups(Node* head, int k) {
    if (!head) return NULL;
    Node* current = head;
    Node* newHead = NULL;
    Node* next = NULL;
    int count = 0;  
    while (current && count < k) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        newHead = current;
        current = next;
        count++;
    }
    if (next) {
        Node* rest = reverseInGroups(next, k);
        head->next = rest;
        if (rest) rest->prev = head;
    }
    return newHead;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    int k = 2;
    cout << "Original List: ";
    printList(head);
    head = reverseInGroups(head, k);
    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    return 0;
}
