#include<bits/stdc++.h>
using namespace std;


// struct LinkedListNode {
//     int val;
//     LinkedListNode *next;
//     LinkedListNode() : val(0), next(nullptr) {}
//     LinkedListNode(int x) : val(x), next(nullptr) {}
//     LinkedListNode(int x, LinkedListNode *next) : val(x), next(next) {}
// };

class Node{
    public:
        int data;
        Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

class Solution{
    public:
        Node* middleNode_two_pointer(Node* head){
            Node *slow = head;
            Node *fast = head;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        Node* middleNode_iterations(Node* head){
            int count_node = 0;
            Node* p = head;

            while(p != NULL){
                count_node++;
                p = p->next;
            }

            p = head;
            for(int i = 0; i<count_node/2; i++){
                p = p->next;
            }

            return p;
        }
};

void insertBegin(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}


void printList(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    

    // Insertion at begining
    Node* head = NULL; // Create an empty list with NULL pointer as a starting pointer
    insertBegin(head,10);
    insertBegin(head,20);
    insertBegin(head,30);

    printList(head);

   
    // Insertion at end
    Node* h1 = NULL;
    Node* t1 = NULL;
    insertTail(h1, t1, 10);
    insertTail(h1, t1, 20);
    insertTail(h1, t1, 30);
    printList(h1);


    Solution obj = Solution();
    int ans = obj.middleNode_two_pointer(head)->data; 
    
    cout<<ans<<endl;
    return 0;
}