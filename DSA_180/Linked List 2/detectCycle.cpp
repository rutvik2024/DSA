#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int val = this->data;

            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }

            cout<<val<<" is deleted successfully..!!"<<endl;
        }
};

class Solution{
    public:
        bool detectCycle(Node *head)
        {
            Node* slow = head;
            Node* fast = head;

            while(fast && fast->next){

                slow = slow->next;
                fast = fast->next->next;
                
                if(slow == fast)
                    return true;
            }
            
            return false;
        }

        // hash approach
        // Time complexity : O(N)
        // Space complexity : O(N)
        bool detectCycle_hash(Node *head)
        {
            unordered_set<Node*> st;
            Node* temp = head;

            while(temp){
                if(st.find(temp) != st.end())
                    return true;

                st.insert(temp);
                temp = temp->next;
            }

            return false;
        }

};

