#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int data){
  this->data=data;
  this->left=NULL;
  this->right =NULL;
}
};
node* insertintoBST(node* root, int data){
  if(root==NULL){
    root=new node(data);
    return root;
  }
  else{
    if(root->data>data){
      root->left=insertintoBST(root->left,data);
    }
    else{
      root->right=insertintoBST(root->right,data);
    }
  }
  return root;
}
void inputdata(node* &root, int n){
//   int data;
//   cin>>data;
//   while(data!=-1){
//     root=insertintoBST(root,data);
//     cin>>data;
//   }

  for(int i = 0; i<n; i++){
    int data;
    cin>>data;
    root=insertintoBST(root,data);
  }
  
}
node* min(node* root){
  node* temp = root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}
node* max(node* root){
  node* temp = root;
  while(temp->right!=NULL){
    temp=temp->right;
  }
  return temp;
}
// node* deletefromBST(node* &root,int data){
//   if(root==NULL){
//     return root;
//   }
//   if(root->data==data){
//     if(root->left==NULL&&root->right==NULL){
//       delete root;
//       return NULL;
//     }
//     }
//     else if(root->left!=NULL&&root->right==NULL){
//       node* temp = root->left;
//       delete root;
//       return temp;
//     }
//     else if(root->left==NULL&&root->right!=NULL){
//       node* temp = root->right;
//       delete root;
//       return temp;
//     }
//     else if(root->left!=NULL&&root->right!=NULL){
//       node* temp=max(root->left);
//       root=temp;
//       delete temp;
//       return root;
//     }
//     else if(root->data >data){
//       root->left=deletefromBST(root->left , data);
//       return root;
//     }
//     else{
//       root->right=deletefromBST(root->right,data);
//       return root;
//     }
// }
node* buildtree(node* root){
  cout<<"enter the data"<<endl;
  int data;
  cin>>data;
  root = new node(data);
  if(data==-1){
    return NULL;
  }
  cout<<"enter data for inserting in left of "<<data<<endl;
  root->left=buildtree(root->left);
  cout<<"enter data for inserting in right of "<<data<<endl;
  root->right=buildtree(root->right);
  return root;
}

node* inorder(node* root){
  if(root==NULL){
    return NULL;
  }
  
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
  return root;
}
node* preorder(node* root){
  if(root==NULL){
    return NULL;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  return root;
}
node* postorder(node* root){
  if(root==NULL){
    return NULL;
  }
  
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
  return root;
}


int depth(node* root){
  if(root==NULL){
    return 0;
  }
  int leftdepth = depth(root->left);
  int rightdepth=depth(root->right);
  if(leftdepth>rightdepth){
    return leftdepth+1;
  }
  else{
    return rightdepth+1;
  }
}


int maxdist(node* root){
  if(root==NULL){
    return 0;
  }
  int leftdepth = depth(root->left);
  int rightdepth=depth(root->right);
  return leftdepth+rightdepth;
}
node* levelordertraversal(node* root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* temp=q.front();
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left){
      q.push(temp->left);
    }
  
   if(temp->right){
      q.push(temp->right);
    }
    }
  return root;
}

// Function to find height of a node in BST from root
int findNodeHeight(node* root, int value) {
    if (root == NULL) {
        return -1;
    }
    else if (root->data == value) {
        return 0;
    }
    else if (root->data > value) {
        return 1 + findNodeHeight(root->left, value);
    }
    else {
        return 1 + findNodeHeight(root->right, value);
    }
}



// node* spiralordertraversal(node* root){
//   queue<node*> q;
//   int n= depth(root);
//   int i;
//   q.push(root);
//   while(!q.empty()){
//     int levelSize = q.size();
//     for(i = 0; i < n;i++){
//     //   if(q.empty()){
//     //     break;
//     //   }
//     //   cout<<"I: "<<cur_height<< " Q: "<<q.front()->data<<endl;
//       node* temp=q.front();
//       cout<<temp->data<<" ";
//       q.pop();
//       int curr_height = findNodeHeight(root, temp->data);

//       if(curr_height%2 == 1){
//         if(temp->right){
//           q.push(temp->right);
//         }
//         if(temp->left){
//           q.push(temp->left);
//         }
//       }
//       else{
//         if(temp->left){
//         //   i++;
//           q.push(temp->left);
//         }
//         if(temp->right){
//           q.push(temp->right);
//         }
//         // cur_height++;
//       }
//     }
//     // i++;
//   }
    
//   return root;

//   }


void spiralordertraversal(node* root , int *ans, int *x) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    // Create a queue to store the nodes of the BST
    queue<node*> q;
    q.push(root);
    
    // Create a stack to store the nodes of the current level
    stack<node*> s;
    
    // Initialize the direction flag
    bool directionFlag = true;  // left to right
    
    // Traverse the BST level by level
    while (!q.empty()) {
        int levelSize = q.size();
        
        // Traverse the nodes of the current level
        for (int i = 0; i < levelSize; i++) {
            // Pop a node from the front of the queue
            node* curr = q.front();
            q.pop();
            
            // If the direction is left to right, push the children from left to right
            if (!directionFlag) {
                if (curr->left != nullptr) {
                    s.push(curr->left);
                }
                if (curr->right != nullptr) {
                    s.push(curr->right);
                }
            }
            // If the direction is right to left, push the children from right to left
            else {
                if (curr->right != nullptr) {
                    s.push(curr->right);
                }
                if (curr->left != nullptr) {
                    s.push(curr->left);
                }
            }
            
            // Print the data of the current node
            // cout << curr->data << " ";
            ans[(*x)++] = curr->data;
        }
        
        // Push the nodes of the next level into the queue in the required order
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        // Change the direction for the next level
        directionFlag = !directionFlag;
    }
}

int main(){
  

  node* root=NULL;
  // root=buildtree(root);
  // levelordertraversal(root);
  // cout<<endl;
  // inorder(root);
  // cout<<endl;
  // preorder(root);
  // cout<<endl;
  // postorder(root);
  // cout<<endl;
  int n;
  cin>>n;
  cout<<"enter the data to create BST"<<endl;
  inputdata(root, n);
   // cout<<"printing the BST"<<endl;
  // levelordertraversal(root);
  // cout<<endl;
  //5 3 7 4 6 8 
  // inorder(root);

// cout<<"Depth is : "<<depth(root)<<endl;
// cout<<endl;
// cout<<maxdist(root);
  cout<<endl;
  // levelordertraversal(root);
  cout<<endl;
  int x = 0;
  int ans[10005];
spiralordertraversal(root, ans, &x);

    for(int i = 0; i<x;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;







  
  return 0;
}