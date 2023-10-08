#include<bits/stdc++.h>
using namespace std;

class SLLNode{
    public:
        int data;
        SLLNode* next;

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

            cout<<val<<" is deleted successfully..!!"<<endl;
        }
};

class Solution{
    public:


    // brute force
    // Time complexity : O(m*n). Space complexity : O(1)
    SLLNode* findIntersection_brute(SLLNode *firstHead, SLLNode *secondHead){
        
        SLLNode* l2 = secondHead;

        while(l2 != NULL){
            SLLNode* l1 = firstHead;

            while(l1 != NULL){
                if(l1 == l2){
                    return l1;
                }

                l1 = l1->next;
            }

            l2 = l2->next;
        }
    }


    // Using hash
    // Time complexity: O(m+n). space complexity: O(m)
    SLLNode* findIntersection_better(SLLNode *firstHead, SLLNode *secondHead){
        unordered_set<SLLNode*> llhash;

        while(firstHead != NULL){
            llhash.insert(firstHead);
            firstHead = firstHead->next;
        }

        while(secondHead != NULL){
            if(llhash.find(secondHead) != llhash.end())
                return secondHead;

            secondHead = secondHead->next;
        }

        return NULL;
    }

    // difference length
    // Time complexity : O(m+n)

    int getListLength(SLLNode *head){
        int count = 0;
        SLLNode* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }

        return count;
    }

    SLLNode* findIntersection_diff(SLLNode *firstHead, SLLNode *secondHead){
        int len_l1 = getListLength(firstHead);
        int len_l2 = getListLength(secondHead);

        SLLNode* d1 = firstHead;
        SLLNode* d2 = secondHead;

        // int diff = len_l1-len_l2;

        while(len_l1 < len_l2){
            len_l2--;
            d2 = d2->next;
        }

        while(len_l1 > len_l2){
            len_l1--;
            d1 = d1->next;
        }

        while(d1){
            if(d1 == d2){
                return d1;
            }

            d1 = d1->next;
            d2 = d2->next;
        }


        return NULL;
    }

    // Optimal Approach
    // Time complexity : O(m+n)
    // Space complexity: O(1)

    SLLNode* findIntersection_diff(SLLNode *firstHead, SLLNode *secondHead){
        SLLNode* d1 = firstHead;
        SLLNode* d2 = secondHead;

        while(d1 != d2){
            d1 = d1 == NULL? secondHead : d1->next;
            d2 = d2 == NULL? firstHead : d2->next;
        }


        return d1;
    } 
};

