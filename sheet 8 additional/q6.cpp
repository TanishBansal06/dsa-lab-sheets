#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
Node* buildTreeUtil(vector<int>& in, vector<int>& post, int& idx, int l, int r, unordered_map<int,int>& mp) {
    if (l > r) return NULL;
    int rootVal = post[idx--];
    Node* root = new Node(rootVal);
    int mid = mp[rootVal];
    root->right = buildTreeUtil(in, post, idx, mid + 1, r, mp);
    root->left = buildTreeUtil(in, post, idx, l, mid - 1, mp);
    return root;
}
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    int idx = postorder.size() - 1;
    return buildTreeUtil(inorder, postorder, idx, 0, inorder.size() - 1, mp);
}
int main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    Node* root = buildTree(inorder, postorder);
    return 0;
}
