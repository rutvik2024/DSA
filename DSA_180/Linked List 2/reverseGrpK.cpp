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

        // Take you forward
        // Time complexity : O(N) and space complexity : O(1)
        // Here if group size is less than k then it will not reverse it.
        // Question : https://leetcode.com/problems/reverse-nodes-in-k-group/
        Node* reverseKGroup_iter(Node* head, int k){
            // Create Dummmy node who always point to first node of the group list first node.

            Node* dummy = new Node(0);
            dummy->next = head;

            // Create pointer who help for reverse
            Node* curr = dummy, *nex = dummy, *prev = dummy;

            // we calculate len of list
            int count = 0;
            while(curr->next){
                count++;
                curr = curr->next;
            }

            // Now reverse in group will be happen
            while(count >= k){
                curr = prev->next;
                nex = curr->next;

                for(int i=1; i<k; i++){
                    curr->next = nex->next;
                    nex->next = prev->next;
                    prev->next = nex;
                    nex = curr->next;
                }
                prev = curr;
                count -=k;
            }

            return dummy->next;
        }


        // Love babbar recursive method
        // Time Complexity : O(N) and Space complexity: O(N)
        // Here is group size less than k it will do reverse
        Node* reverseKGroup_rec(Node* head, int k){
            
            // Base case
            if(head == NULL){
                return NULL;
            }

            // Reverse group of k nodes iteratively
            Node* curr = head, *prev = NULL, *next = NULL;
            int count = 0;
            while(curr != NULL && count < k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            // recursively reverse nodes
            if(next != NULL){
                head->next = reverseKGroup_rec(next, k);
            }

            // Return reversed linked list
            return prev;
        }


        // Reverse into size of different group. Each group size is given in array
        // Question : https://www.codingninjas.com/studio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
        // Time Complexity : O(N) && Space Complexity : O(1)
        Node *getListAfterReverseOperation(Node *head, int n, int b[]){
            if(head == NULL)
                return head;

            Node* dummy = new Node(0);
            dummy->next = head;
            Node* curr = dummy, *nex = dummy, *prev = dummy;

            for(int i = 0; i<n; i++){
                if(prev == NULL || prev->next == NULL)
                    break;

                if(b[i] == 0)
                    continue;

                curr = prev->next;
                nex = curr->next;

                for(int j = 1; j<b[i] && curr != NULL && curr->next != NULL; j++){
                    curr->next = nex->next;
                    nex->next = prev->next;
                    prev->next = nex;
                    nex = curr->next;
                }

                prev = curr;
            }

            return dummy->next;
        }

        // Above Question but using recursion
        Node* reverserK_rec(Node* head, int i, int b[], int n){
            // If linked list is empty or array is over then stop.
            if(head == NULL || i >= n)
                return head;

            // reverse list using 3 pointer method
            Node* curr = head, *prev = NULL, *nex = NULL;
            int count = 0;
            while(count < b[i] && curr != NULL){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
                count++;
            }

            // Recursively Call node
            if(nex != NULL)
                head->next = reverserK_rec(nex, i+1, b, n);
            

            else if(curr != NULL && i<n-1)
                prev = reverserK_rec(curr, i+1, b, n);

            return n==1 ? curr : prev;
        }

        Node *getListAfterReverseOperation_rec(Node *head, int n, int b[]){
            if(head != NULL)
                return reverserK_rec(head, 0, b, n);
            
            return head;
        }
};

