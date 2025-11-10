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
node* insert(node* root,int ele){
    if(root==NULL){
        return new node(ele);
    }
    if(root->data>ele){
       root->left =  insert(root->left,ele);
    }
    else if(root->data<ele){
       root->right = insert(root->right,ele);
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
     vector<int> v = {2, 1, -1, -1, 4, 3, -1, -1, 6, -1, -1};
   node* root = binarytree(v);
   insert(root,5);
   inorder(root);
     //cout<<endl;
    //  inorder(binarytree(v));
    //  cout<<endl;
    //  post(binarytree(v));
    return 0;
}
