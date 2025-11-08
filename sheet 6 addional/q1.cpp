#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Solution {
  public:
    pair<Node*, Node*> splitList(Node* head) {
        if (head == NULL || head->next == head)
            return {head, NULL};
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head)
            fast = fast->next;
        Node* head1 = head;
        Node* head2 = slow->next;
        slow->next = head1;
        fast->next = head2;
        return {head1, head2};
    }
};
void printList(Node* head) {
    if (head == NULL)
        return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head;
    cout << "Original Circular List: ";
    printList(head);
    Solution obj;
    pair<Node*, Node*> res = obj.splitList(head);
    cout << "first half";
    printList(res.first);
    cout << "second half";
    printList(res.second);
    return 0;
}
