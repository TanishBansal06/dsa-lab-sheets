#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int val) : data(val), next(NULL), prev(NULL), random(NULL) {}
};
void correctRandomPointer(Node* head) {
    if (!head) return;
    Node* start = head;
    Node* end = head;
    while (end->next)
        end = end->next;
    if (start->random == end)
        start->random = start->next;
    else if (end->random == start)
        end->random = end->prev;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->random)
            cout << "(" << temp->random->data << ")";
        if (temp->next)
            cout << " <-> ";
        temp = temp->next;
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
    head->random = head->next->next->next;
    cout << "Before correction:\n";
    printList(head);
    correctRandomPointer(head);
    cout << "After correction:\n";
    printList(head);
    return 0;
}
