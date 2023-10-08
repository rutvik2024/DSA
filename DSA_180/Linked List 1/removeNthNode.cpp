#include<bits/stdc++.h>
using namespace std;

class SLLNode{
    public:
        int data;
        SLLNode* next;

        SLLNode(){
            this->data = 0;
            next = NULL;
        }

        SLLNode(int data){
            this->data = data;
            this->next = NULL;
        }

        ~SLLNode(){
            int val = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }

            cout<<"Val "<<val<<" is deleted..!!"<<endl;
        }
};


class Solution{
    
    public:
        void insertNodeAtPos(SLLNode* &head, SLLNode* &tail, int pos, int data){
            SLLNode* temp = new SLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }

            if(pos == 1){
                temp->next = head;
                head = temp;
                return;
            }

            int count = 1;
            SLLNode* p = head;
            while(count < pos - 1){
                count++;
                p = p->next;
            }

            if(p != tail){
                temp->next = p->next;
                p->next = temp;
                return;
            }

            tail->next = temp;
            tail = temp;
            return;
        }
        // This Approach has time complexity of 2n n for traversal and n for to reach that node
        void removeNthFromEnd_2n(SLLNode* &head, SLLNode* &tail, int pos){
            if(head == NULL){
                cout<<"Removal is not possible"<<endl;
                return;
            }

            SLLNode* temp = head;
            if(pos == 0){
                head = head->next;
                temp->next = NULL;
                delete temp;
                return;
            }

            int count = 0;
            while(count < pos-1 && temp){
                count++;
                temp = temp->next;
            }
            SLLNode* p = temp->next;
            temp->next = temp->next->next;
            p->next = NULL;
            delete p;
        }


        // This Approach has time complexity of n
        void removeNthFromEnd_n(SLLNode* &head, SLLNode* &tail, int pos){
            SLLNode* dummy = new SLLNode();
            dummy->next = head;
            SLLNode *slow = dummy, *fast = dummy;

            for(int i = 1; i<=pos; i++){
                fast = fast->next;
            }

            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            SLLNode *p = slow->next;
            slow->next = slow->next->next;
            head = dummy->next;

            p->next = NULL;
            delete p;
        }


        int printList(SLLNode* &head){
            SLLNode* temp = head;
            int count = 0;

            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
                count++;
            }

            cout<<endl;
            return count;
        }
};


int main(){
    SLLNode* head = NULL, *tail = NULL;
    Solution obj = Solution();

    obj.insertNodeAtPos(head, tail, 1, 10);
    obj.insertNodeAtPos(head, tail, 2, 20);
    obj.insertNodeAtPos(head, tail, 1, 30);
    obj.insertNodeAtPos(head, tail, 4, 40);
    obj.insertNodeAtPos(head, tail, 3, 15);
    // obj.insertNodeAtPos(head, tail, 3, 5);
    int len = obj.printList(head);

    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    cout<<"Len is : "<<len<<endl;

    int nodeToDeleteFromLast;
    cin>>nodeToDeleteFromLast;


    // obj.removeNthFromEnd_2n(head, tail, len-nodeToDeleteFromLast);
    obj.removeNthFromEnd_n(head, tail, nodeToDeleteFromLast);
    len = obj.printList(head);

    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    cout<<"Len is : "<<len<<endl;


    return 0;
}