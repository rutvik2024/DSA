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
    void deleteNode(SLLNode* node){
        node->data = node->next->data;
        SLLNode* p = node;
        node->next = node->next->next;
        p->next = NULL;
        delete p;
    }
};
