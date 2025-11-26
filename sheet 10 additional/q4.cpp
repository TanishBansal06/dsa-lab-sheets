#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};
Node* insertEnd(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
    return head;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* getIntersection(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* result = NULL;
    while (head1) {
        s.insert(head1->data);
        head1 = head1->next;
    }
    while (head2) {
        if (s.count(head2->data)) {     
            result = insertEnd(result, head2->data);
        }
        head2 = head2->next;
    }
    return result;
}
Node* getUnion(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* result = NULL;
    while (head1) {
        s.insert(head1->data);
        head1 = head1->next;
    }
    while (head2) {
        s.insert(head2->data);
        head2 = head2->next;
    }
    for (int x : s) {
        result = insertEnd(result, x);
    }
    return result;
}
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    head1 = insertEnd(head1, 10);
    head1 = insertEnd(head1, 15);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 20);
    head2 = insertEnd(head2, 8);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 10);
    Node* intersection = getIntersection(head1, head2);
    Node* uni = getUnion(head1, head2);
    cout << "Intersection List: ";
    printList(intersection);
    cout << "Union List: ";
    printList(uni);
    return 0;
}
