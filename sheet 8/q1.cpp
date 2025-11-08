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
node* binarytree(vector<int> &v){
    i++;
    if(v[i]==-1){
        return NULL;
    }
    node* root = new node(v[i]);
    root->left = binarytree(v);
    root->right = binarytree(v);
    return root;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void post(node* root){
    if(root==NULL){
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data;
}
int main() {
     vector<int> v;
     for(int i=0;i<11;i++){
         int n;
         cin>>n;
         v.push_back(n);
     }
    // vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
     preorder(binarytree(v));
     //cout<<endl;
    //  inorder(binarytree(v));
    //  cout<<endl;
    //  post(binarytree(v));
    return 0;
}
