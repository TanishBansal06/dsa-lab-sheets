#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;
    bstToDLL(root->left, head, prev);
    if (!prev) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    bstToDLL(root->right, head, prev);
}
Node* mergeDLL(Node* a, Node* b) {
    Node* head = NULL;
    Node* tail = NULL;
    while (a && b) {
        Node* temp;
        if (a->val < b->val) {
            temp = a; 
            a = a->right;
        } else {
            temp = b; 
            b = b->right;
        }
        if (!head) head = tail = temp;
        else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }
    Node* rem = (a ? a : b);
    while (rem) {
        if (!head) head = tail = rem;
        else {
            tail->right = rem;
            rem->left = tail;
            tail = rem;
        }
        rem = rem->right;
    return head;
}
Node* mergeTwoBSTs(Node* t1, Node* t2) {
    Node *h1 = NULL, *p1 = NULL;
    Node *h2 = NULL, *p2 = NULL;
    bstToDLL(t1, h1, p1);
    bstToDLL(t2, h2, p2);
    if (p1) p1->right = NULL;
    if (p2) p2->right = NULL;
    return mergeDLL(h1, h2);
}
int main() {
    Node* T1 = new Node(20);
    T1->left = new Node(10);
    T1->right = new Node(30);
    T1->left->left = new Node(25);
    T1->left->right = new Node(100);
    T1->right->right = new Node(50);
    Node* T2 = new Node(5);
    T2->right = new Node(70);
    Node* head = mergeTwoBSTs(T1, T2);
    while (head) {
        cout << head->val << " <—> ";
        head = head->right;
    }
    cout << "null\n";
}
