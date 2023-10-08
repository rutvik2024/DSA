//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
    
        bool findNode(Node* root, int node, queue<Node*> &q){
            
            // Can't find node
            if(root == NULL)
                return false;
                
            // Find node
            if(root->data == node){
                q.push(root);
                return true;
            }
                
            bool flag = false;
                
            if(root->data > node){
                flag = findNode(root->left, node, q);
            }
            
            else{
                flag = findNode(root->right, node, q);
            }
            
            if(flag){
                q.push(root);
                return true;
            }
            
            return false;
        }
    
        
        Node* LCA(Node *root, int n1, int n2)
        {
            queue<Node*> q1;
            queue<Node*> q2;
            
            bool flag1 = findNode(root, n1, q1); // Finding node 1 and update its queue with its parent
            bool flag2 = findNode(root, n2, q2); // Finding node 2 and update its queue with its parent
            
            
            
            // Took both subtree at same level
            while((!q1.empty() && !q2.empty()) && (q1.size() != q2.size())){
                if(q1.size() > q2.size())
                    q1.pop();
                    
                else
                    q2.pop();
            }
            
            
            // start matching
            while((!q1.empty() && !q2.empty()) && (q1.front() != q2.front())){
                q1.pop();
                q2.pop();
            }
            
            
            return q1.front();
        }

};


//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends