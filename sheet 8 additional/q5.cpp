#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
Node* buildTreeUtil(vector<int>& pre, vector<int>& in, int& idx, int l, int r, unordered_map<int,int>& mp) {
    if (l > r) return NULL;
    int rootVal = pre[idx++];
    Node* root = new Node(rootVal);
    int mid = mp[rootVal];
    root->left = buildTreeUtil(pre, in, idx, l, mid - 1, mp);
    root->right = buildTreeUtil(pre, in, idx, mid + 1, r, mp);
    return root;
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    int idx = 0;
    return buildTreeUtil(preorder, inorder, idx, 0, inorder.size() - 1, mp);
}
int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    Node* root = buildTree(preorder, inorder);
    return 0;
}
