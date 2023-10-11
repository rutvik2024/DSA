#include<bits/stdc++.h>
using namespace std;

struct AVLNode {
    int key, height;
    AVLNode *left, *right;
    int count; // count of persons who like this number

    AVLNode(int key) {
        this->key = key;
        this->height = 1;
        this->left = this->right = NULL;
        this->count = 0;
    }
};

int getHeight(AVLNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(AVLNode *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(AVLNode *node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

AVLNode* rotateLeft(AVLNode *node) {
    AVLNode *newRoot = node->right;
    AVLNode *temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

AVLNode* rotateRight(AVLNode *node) {
    AVLNode *newRoot = node->left;
    AVLNode *temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

AVLNode* insert(AVLNode *node, int key) {
    if (node == NULL) return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // key already exists
        return node;

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

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

int search(AVLNode *node, int key) {
    if (node == NULL) return 0;

    if (key < node->key)
        return search(node->left, key);

    if (key > node->key)
        return search(node->right, key);

    return node->count;
}

void update(AVLNode *node, int start, int end, int delta) {
    if (node == NULL) return;

    if (start <= node->key && end >= node->key)
        node->count += delta;

    if (node->left != NULL && start < node->key)
        update(node->left, start, end, delta);

    if (node->right != NULL && end > node->key)
        update(node->right, start, end, delta);

    updateHeight(node);
}

int main() {
    int n, q;
    cin >> n;

    vector<int> values;

    // reading the ranges and adding the values to the vector
    for (int i = 0; i < n; i++) {
        int l, r;
        cout<<"Enter l"<<endl;

        cin >> l;

        cout<<"Enter r"<<endl;
        cin >> r;
        values.push_back(l);
        values.push_back(r);
    }

    cout<<"Enter Queries "<<endl;

    cin >> q;

    vector<int> queries(q);

    // reading the queries and adding the values to the vector
    for (int i = 0; i < q; i++) {
        int x;
        cout<<"Enter each queries values : "<<endl;
        cin >> x;
        queries[i] = x;
        values.push_back(x);
    }

    // sorting the vector and removing duplicates
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    // creating a mapping from original values to compressed values
    map<int, int> mapping;
    for (int i = 0; i < values.size(); i++)
        mapping[values[i]] = i;

    AVLNode *root = NULL;

    // processing the ranges and updating the AVL tree
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l = mapping[l];
        r = mapping[r];
        root = insert(root, l);
        root = insert(root, r + 1);
        update(root, l, r, 1);
    }

    long long answer = 0;

    // processing the queries and counting the number of persons who like each number
    for (int i = 0; i < q; i++) {
        int x = mapping[queries[i]];
        int count = search(root, x);
        answer += count;
    }

    cout << answer << endl;

    return 0;
}

