// Online C++ compiler to run C++ program online

#include <iostream>
#include<vector>
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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
node* su(node* root){
    node* s=root;
    while(s->left != NULL){
        s = s->left;
    }
    return s;
}
node* ddelete(node* root,int ele){
    if(root==NULL){
        return NULL;
    }
    if(root->data>ele){
        root->left = ddelete(root->left,ele);
    }
    else if(root->data<ele){
        root->right = ddelete(root->right,ele);
    }
    else{
        if(root->left==NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left && root->right){
            node* suc = su(root->right);
            root->data = suc->data;
            root->right = ddelete(root->right, suc->data);
        }
    }
    return root;
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
   inorder(root);
   cout<<endl;
   ddelete(root,4);
   inorder(root);
   
     //cout<<endl;
    //  inorder(binarytree(v));
    //  cout<<endl;
    //  post(binarytree(v));
    return 0;
}
