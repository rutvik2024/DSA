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


};

class Solution{

    public:
    
    void insertAtEnd(SLLNode* &head, SLLNode* &tail, int data){
        SLLNode* temp = new SLLNode(data);

        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
        return;
    }

    SLLNode* AddNum(SLLNode* list1, SLLNode* list2){
        SLLNode* ans = NULL, *tail = NULL;

        int sum = 0;
        int rem = 0;
        int carry = 0;

        while(list1 != NULL && list2 != NULL){
            sum = carry+list1->data+list2->data;
            rem = sum%10;
            insertAtEnd(ans, tail, rem);
            carry = sum/10;

            list1 = list1->next;
            list2 = list2->next;
        }

        while(list1){
            sum = carry+list1->data;
            rem = sum%10;
            insertAtEnd(ans, tail, rem);
            carry = sum/10;

            list1 = list1->next;
        }

        while(list2){
            sum = carry+list2->data;
            rem = sum%10;
            insertAtEnd(ans, tail, rem);
            carry = sum/10;

            list2 = list2->next;
        }

        if(carry != 0){
            insertAtEnd(ans, tail, carry);
        }

        return ans;
    }

    void printList(SLLNode* &head){
            SLLNode* temp = head;
        
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }

            cout<<endl;
        }

};



int main(){

    SLLNode* head = NULL, *tail = NULL;
    Solution obj = Solution();

    obj.insertAtEnd(head, tail, 5);
    obj.insertAtEnd(head, tail, 6);
    obj.insertAtEnd(head, tail, 7);

    SLLNode* head1 = NULL, *tail1 = NULL;

    obj.insertAtEnd(head1, tail1, 4);
    obj.insertAtEnd(head1, tail1, 7);
    obj.insertAtEnd(head1, tail1, 5);
    obj.insertAtEnd(head1, tail1, 9);
    obj.insertAtEnd(head1, tail1, 9);

    SLLNode *ans = obj.AddNum(head, head1);

    obj.printList(ans);
    cout<<"Ans: "<<ans->data<<endl;
    


    return 0;
}
