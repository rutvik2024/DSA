#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;


        Node(int value) {
            val = value;
            next = NULL;
            random = NULL;
        }
};

Node* cloneList_brute(Node* head){
    if(head == NULL)
        return NULL;

    unordered_map<Node*, Node*> mp;
    Node* temp = head;

    while(temp){
        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp){
        Node* node = mp[temp];
        node->next = (temp->next) ? mp[temp->next]: NULL;
        node->random = (temp->random) ? mp[temp->random] : NULL;
        temp = temp->next;
    }

    return mp[head];
}


Node* cloneList_optimal(Node* head){
    Node* temp = head;
    while(temp){
        Node* nn = new Node(temp->val);
        nn->next = temp->next;
        temp->next = nn;
        temp = nn->next;
    }

    Node* iter = head;
    while(iter){
        if(iter->random){
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    Node* dummy = new Node(0);
    temp = dummy;
    iter = head;
    Node* fast;

    while(iter){
        fast = iter->next->next;
        temp->next = iter->next;
        iter->next = fast;
        temp = temp->next;
        iter = fast;
    }

    return dummy->next;
}






void printList(Node* head) {
    while(head != NULL) {
        cout<<head->val<<':';
        head->next != NULL ? cout<<head->next->val:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}




int main(){
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    printList(head);

    cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    Node* newHead = cloneList_optimal(head);
    printList(newHead);

    return 0;
}