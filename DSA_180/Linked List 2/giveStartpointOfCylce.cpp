#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Brute force solution Using hash table
// Time Complexity : O(N)
// Space Complexity: O(N) 
Node *firstNode_brute(Node *head)
{   
    unordered_set<Node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

// using Two pointer solution
// Time Complexity : O(N)
// Space Complexity: O(1) 
Node *firstNode_optim(Node *head)
{   
    if(head == NULL||head->next == NULL) return NULL;


    Node* slow = head;
    Node* fast = head;
    Node* entry = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }

            return slow;
        }
    }
    return NULL;
}