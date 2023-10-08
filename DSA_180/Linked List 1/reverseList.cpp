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

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertBegin(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertEnd(Node* &head, Node* &tail, int data){
    Node *temp = new Node(data);

    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }

    tail->next = temp;
    tail = temp;
}


// Approach 1: Iterative approach
class solution
{
    public:
        Node* reverseList(Node* head){
            Node* next = NULL;
            Node* prev = NULL;
            Node* curr = head;

            while(curr != NULL){
                next = curr->next; 
                curr->next = prev; 
                prev = curr;
                curr = next;
            }

            return prev;
        }  

        void listReverse(Node* head, Node* curr, Node* prev){
            if(curr == NULL){
                head = prev;
                return;
            }

            Node* forward = curr->next;
            listReverse(head, forward, curr);
            curr->next = prev;
        } 

        Node* revervse_rec(Node* head){
            Node* curr = head;
            Node* prev = NULL;
            listReverse(head, curr, prev);
            return head;
        }

};

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

    cout<<"Before Reverse List: "<<endl;
    printList(head);

    solution obj = solution();
    
    head = obj.revervse_rec(head);
    cout<<"After Reverse List : "<<endl;
    printList(head);
   
    
    cout<<"Another List: \n";
    // Insertion at end
    Node* h1 = NULL;
    Node* t1 = NULL;
    insertEnd(h1, t1, 10);
    insertEnd(h1, t1, 20);
    insertEnd(h1, t1, 30);
    printList(h1);


    


    return 0;
}