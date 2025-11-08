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
bool search(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    return search(root->left,key) || search(root->right,key);
}
bool ssearch(node* root,int key){
    
    while(root != NULL){
        if(root->data==key){
            return true;
        }
        else if(key<root->data){
           root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return false;
}
int main() {
    //  vector<int> v;
    //  for(int i=0;i<11;i++){
    //      int n;
    //      cin>>n;
    //      v.push_back(n);
    //  }
    vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    // preorder(binarytree(v));
     //cout<<endl;
    //  inorder(binarytree(v));
    //  cout<<endl;
    //  post(binarytree(v));
    node* root = binarytree(v);
    cout<<search(root,5);
  cout<<ssearch(root,5);
    return 0;
}
