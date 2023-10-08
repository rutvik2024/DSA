#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr) {}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

void insertEnd(Node* &head, Node* &tail, int data){
    Node *temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}


Node* mergeList(Node* a, Node* b){
    Node* temp = new Node(0);
    Node* ans = temp;

    while(a && b){
        if(a->data < b->data){
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }

        else{
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }

    if(a)
        temp->child = a;
    
    if(b)
        temp->child = b;

    return ans->child;
}


Node* falttern(Node* head){
    // If head is last node. 
    // Base case
    if(head == NULL || head->next == NULL)
        return head;

    // If it is not last then go till last node in list
    head->next = falttern(head->next);

    // after getting last node merge last two node list. After that I modify that head pointer.
    head = mergeList(head, head->next);

    // So we return that modified head value.
    return head;
}