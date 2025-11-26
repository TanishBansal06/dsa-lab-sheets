#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
bool checkDuplicates(Node* root, unordered_set<int>& seen) {
    if (root == NULL)
        return false;
    if (seen.count(root->data))
        return true;
    seen.insert(root->data);
    return checkDuplicates(root->left, seen) ||
           checkDuplicates(root->right, seen);
}
bool containsDuplicate(Node* root) {
    unordered_set<int> seen;
    return checkDuplicates(root, seen);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2);  
    if (containsDuplicate(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
    return 0;
}
