// Online C++ compiler to run C++ program online

#include <iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};
static int i=-1;
node *helper(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (root->data > val)
    {
        root->left = helper(root->left, val);
    }
    else
    {
        root->right = helper(root->right, val);
    }
    return root;
}
node *bst(vector<int> &arr)
{
    node *root = NULL;
    for (int val : arr)
    {
        root = helper(root, val);
    }
    return root;
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

int main() {
    //  vector<int> v;
    //  for(int i=0;i<11;i++){
    //      int n;
    //      cin>>n;
    //      v.push_back(n);
    //  }
     vector<int> v = {2, 1, 4, 3, 5,};
   node* root = bst(v);
   cout<<height(root)-1;
   cout<<endl;
   int minn = min(height(root->left),height(root->right));
   cout<<minn;
     //cout<<endl;
    //  inorder(binarytree(v));
    //  cout<<endl;
    //  post(binarytree(v));
    return 0;
}
