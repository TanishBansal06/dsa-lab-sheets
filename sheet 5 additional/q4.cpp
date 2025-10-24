#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int new_data) {
        data = new_data;
        next = NULL;
    }
};
Node *rotate(Node *head, int k) {
    if (k == 0 || head == NULL)
        return head;
    for (int i = 0; i < k; ++i) {
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}
void printList(Node *node) {
    while (node != NULL) {
        cout << node->data;
        if(node->next != NULL){
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}
int main() {

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head = rotate(head, 5);
    printList(head);
}
