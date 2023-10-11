#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int key;
    Node* left; 
    Node* right;
    int height;
};

class AVLTree {
public:
    Node* root;
    AVLTree() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return height(node->right) - height(node->left);
    }
    void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

void printInorder(AVLTree* tree) {
    cout << "Inorder Traversal: ";
    inorder(tree->root);
    cout << endl;
}
Node* search(Node* node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

bool contains(AVLTree* tree, int key) {
    Node* node = search(tree->root, key);
    return (node != NULL);
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL) {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);
    if (balance > 1 && balanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && balanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void deleteNode(AVLTree* tree, int key) {
    tree->root = deleteNode(tree->root, key);
}


    Node* rotateRight(Node* node) {
        Node* new_root = node->left;
        Node* new_left = new_root->right;
        new_root->right = node;
        node->left = new_left;
        node->height = max(height(node->left), height(node->right)) + 1;
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
        return new_root;
    }

    Node* rotateLeft(Node* node) {
        Node* new_root = node->right;
        Node* new_right = new_root->left;
        new_root->left = node;
        node->right = new_right;
        node->height = max(height(node->left), height(node->right)) + 1;
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
        return new_root;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            node = new Node();
            node->key = key;
            node->left = NULL;
            node->right = NULL;
            node->height = 1;
        }
        else if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
};
const int MD = 1e9 + 7;
int main() {
    long long N, A, B, Q;
    cin >> N >> A >> B >> Q;

    long long L[N];
    long long R[N];
    L[0] = A;
    R[0] = B;
    for (int i = 1; i < N; i++) {
        L[i] = L[i - 1] * (A * i + B) % MD;
        R[i] = L[i] + (A * i + B) % MD;
    }

    long long q[Q];
    q[0] = A + B;
    for (int i = 1; i < Q; i++) {
        q[i] = q[i - 1] * (A * i + B) % MD;
    }

int sum=0;
for(int i=0;i<Q;i++){
    for(int j=0;j<N;j++){
        if(q[i]>=L[j]&&q[i]<=R[j]){
            sum++;
        }
    }
}
cout<<sum<<endl;

    // int n;
    // cin >> n;
    // unordered_map<int, int> ump;
    
    // for(int i = 0; i < n; i++){
    //     int a, b;
    //     cin >> a >> b;
        
    //     for(int j = a; j <= b; j++){
    //         ump[j]++;
    //     }
    // }
    // int query;
    // cin >> query;
    
    // int sum = 0;
    // for(int i = 0; i < query; i++){
    //     int a;
    //     cin >> a;
    //     if(ump.find(a) != ump.end()){
    //         sum += ump[a];
    //     }
    // }
    // cout << sum << endl;
}



//     AVLTree tree;
//     tree.root = tree.insert(tree.root, 10);
//     tree.root = tree.insert(tree.root, 20);
//     tree.root = tree.insert(tree.root, 30);
//     tree.root = tree.insert(tree.root, 40);
//     tree.root = tree.insert(tree.root, 50);
//     tree.root = tree.insert(tree.root, 25);





// #include <iostream>
// #include <set>
// #include <unordered_map>
// using namespace std;

// const int MAXN = 1e5 + 5;
// const int MD = 1e9 + 7;

// class Node {
// public:
//     int key;
//     int height;
//     int size;
//     Node* left;
//     Node* right;
// };

// class AVLTree {
// public:
//     Node* root;
//     AVLTree() {
//         root = NULL;
//     }

//     int height(Node* node) {
//         if (node == NULL) {
//             return 0;
//         }
//         return node->height;
//     }

//     int size(Node* node) {
//         if (node == NULL) {
//             return 0;
//         }
//         return node->size;
//     }

//     Node* newNode(int key) {
//         Node* node = new Node();
//         node->key = key;
//         node->left = NULL;
//         node->right = NULL;
//         node->height = 1;
//         node->size = 1;
//         return node;
//     }

//     Node* rightRotate(Node* y) {
//         Node* x = y->left;
//         Node* T2 = x->right;

//         x->right = y;
//         y->left = T2;

//         y->height = max(height(y->left), height(y->right)) + 1;
//         x->height = max(height(x->left), height(x->right)) + 1;

//         y->size = size(y->left) + size(y->right) + 1;
//         x->size = size(x->left) + size(x->right) + 1;

//         return x;
//     }

//     Node* leftRotate(Node* x) {
//         Node* y = x->right;
//         Node* T2 = y->left;

//         y->left = x;
//         x->right = T2;

//         x->height = max(height(x->left), height(x->right)) + 1;
//         y->height = max(height(y->left), height(y->right)) + 1;

//         x->size = size(x->left) + size(x->right) + 1;
//         y->size = size(y->left) + size(y->right) + 1;

//         return y;
//     }

//     int getBalance(Node* node) {
//         if (node == NULL) {
//             return 0;
//         }
//         return height(node->left) - height(node->right);
//     }

//     Node* insert(Node* node, int key) {
//         if (node == NULL) {
//             return newNode(key);
//         }

//         if (key < node->key) {
//             node->left = insert(node->left, key);
//         }
//         else if (key > node->key) {
//             node->right = insert(node->right, key);
//         }
//         else {
//             return node;
//         }

//         node->height = max(height(node->left), height(node->right)) + 1;
//         node->size = size(node->left) + size(node->right) + 1;

//         int balance = getBalance(node);

//         if (balance > 1 && key < node->left->key) {
//             return rightRotate(node);
//         }
//         if (balance < -1 && key > node->right->key) {
//             return leftRotate(node);
//         }
//         if (balance > 1 && key > node->left->key) {
//             node->left = leftRotate(node->left);
//             return rightRotate(node);
//         }
//         if (balance < -1 && key < node->right->key) {
//             node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }

// Node* minValueNode(Node* node) {
//     Node* current = node;

//     while (current->left != NULL) {
//         current = current->left;
//     }

//     return current;
// }

// Node* deleteNode(Node* node, int key) {
//     if (node == NULL) {
//         return node;
//     }

//     if (key < node->key) {
//         node->left = deleteNode(node->left, key);
//     }
//     else if (key > node->key) {
//         node->right = deleteNode(node->right, key);
//     }
//     else {
//         if (node->left == NULL || node->right == NULL) {
//             Node* temp = node->left ? node->left : node->right;

//             if (temp == NULL) {
//                 temp = node;
//                 node = NULL;
//             }
//             else {
//                 *node = *temp;
//             }

//             delete temp;
//         }
//         else {
//             Node* temp = minValueNode(node->right);

//             node->key = temp->key;

//             node->right = deleteNode(node->right, temp->key);
//         }
//     }

//     if (node == NULL) {
//         return node;
//     }

//     node->height = max(height(node->left), height(node->right)) + 1;
//     node->size = size(node->left) + size(node->right) + 1;

//     int balance = getBalance(node);

//     if (balance > 1 && getBalance(node->left) >= 0) {
//         return rightRotate(node);
//     }
//     if (balance > 1 && getBalance(node->left) < 0) {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }
//     if (balance < -1 && getBalance(node->right) <= 0) {
//         return leftRotate(node);
//     }
//     if (balance < -1 && getBalance(node->right) > 0) {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }

// Node* kthSmallest(Node* node, int k) {
//     if (node == NULL) {
//         return NULL;
//     }

//     int leftSize = size(node->left);

//     if (leftSize + 1 == k) {
//         return node;
//     }
//     else if (leftSize >= k) {
//         return kthSmallest(node->left, k);
//     }
//     else {
//         return kthSmallest(node->right, k - leftSize - 1);
//     }
// }

// int countNodesInRange(Node* node, int start, int end) {
//     if (node == NULL) {
//         return 0;
//     }

//     if (node->key > end) {
//         return countNodesInRange(node->left, start, end);
//     }
//     else if (node->key < start) {
//         return countNodesInRange(node->right, start, end);
//     }
//     else {
//         return 1 + countNodesInRange(node->left, start, end) + countNodesInRange(node->right, start, end);
//     }
// }
// };
// int main() {
// long long N, A, B, Q;
// cin >> N >> A >> B >> Q;
// long long L[MAXN];
// long long R[MAXN];
// long long compressedL[MAXN];
// long long compressedR[MAXN];
// set<long long> distinct;
// L[0] = A;
// R[0] = B;
// distinct.insert(A);
// distinct.insert(B);
// for (int i = 1; i < N; i++) {
// L[i] = L[i - 1] * (A * i + B) % MD;
// R[i] = L[i] + (A * i + B) % MD;
// distinct.insert(L[i]);
// distinct.insert(R[i]);
// }
// unordered_map<long long, long long> compress;
// int index = 1;
// for (auto val : distinct) {
//     compress[val] = index++;
// }

// for (int i = 0; i < N; i++) {
//     compressedL[i] = compress[L[i]];
//     compressedR[i] = compress[R[i]];
// }

// long long q[Q];
// long long compressedQ[Q];
// set<long long> distinctQ;
// q[0] = A + B;
// distinctQ.insert(q[0]);
// for (int i = 1; i < Q; i++) {
//     q[i] = q[i - 1] * (A * i + B) % MD;
//     distinctQ.insert(q[i]);
// }

// index = 1;
// for (auto val : distinctQ) {
//     compress[val] = index++;
// }

// for (int i = 0; i < Q; i++) {
//     compressedQ[i] = compress[q[i]];
// }

// AVLTree avl;

// for (int i = 0; i < N; i++) {
//     avl.insert(compressedL[i]);
//     avl.insert(compressedR[i] + 1);
// }

// int diff[N + 1];
// memset(diff, 0, sizeof(diff));

// for (int i = 1; i <= N; i++) {
//     Node* nodeL = avl.kthSmallest(i);
//     Node* nodeR = avl.kthSmallest(i + 1);

//     int start = nodeL->key;
//     int end = nodeR->key - 1;

//     diff[start]++;
//     diff[end + 1]--;
// }

// for (int i = 1; i <= N; i++) {
//     diff[i] += diff[i - 1];
// }

// long long ans[Q];

// for (int i = 0; i < Q; i++) {
//     int compressed = compressedQ[i];
//     ans[i] = diff[compressed];
// }

// for (int i = 0; i < Q; i++) {
//     cout << ans[i] << endl;
// }

// return 0;
// }




