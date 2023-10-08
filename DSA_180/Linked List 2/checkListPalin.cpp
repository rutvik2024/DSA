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

    void printList(SLLNode* &head){
        SLLNode* temp = head;
    
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }

    int getListLen(SLLNode* head){
        int count = 0;
        SLLNode* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }

        return count;
    }


    // Brute Force solution
    // Time Complexity : O(N^2)
    // Space Complexity: O(1)    
    bool isPalindrome_brute(SLLNode *head) {
        if(head == NULL)    
            return true;

        int n = getListLen(head);

        for(int i = 0; i<n/2; i++){
            SLLNode* temp = head;
            
            int count = 0;
            while(count < i){
                temp = temp->next;
                count++;
            }
            // cout<<"Temp1 : "<<temp->data<<endl;

            SLLNode* temp2 = head;
            for(int j = 1; j<n-i; j++){
                // cout<<"temp2 in for loop : "<<temp2->data<<endl;
                temp2 = temp2->next;
            }
            
            // cout<<"Temp2 : "<<temp2->data<<endl;
            if(temp->data != temp2->data)
                return false;

            // cout<<"-----------------------------------------"<<endl;
        }

        return true;
    }

    // Better solution using array
    // Time Complexity : O(N)
    // Space Complexity: O(N)    
    bool isPalindrome_array(SLLNode* head){
        if(head == NULL)
            return true;

        // Create an empty array
        vector<int> temp;

        // Insert each list element in to array
        SLLNode* temp_ptr = head;
        while(temp_ptr){
            temp.push_back(temp_ptr->data);
            temp_ptr = temp_ptr->next;
        }

        // Now using two pointer we traverse array and compare left and right value
        int left = 0;
        int right = temp.size()-1;

        while(left < right){
            if(temp[left] != temp[right])
                return false;

            left++;
            right--;
        }

        return true;
    }


    // Optimized solution 
    // Time Complexity : O(N)
    // Space Complexity: O(1) 
    
    bool isPalindrome_optim(SLLNode *head) {
        if(head == NULL)    
                return true;

        // Finding middle element of the list
        SLLNode * slow = head;
        SLLNode * fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // cout<<"Slow: "<<slow->data<<endl;

        // Now we reverse element from middle(slow->next) to end of list pointer.
        
        SLLNode* curr = slow->next; // start point from where I start reversing.
        SLLNode* prev = NULL;
        SLLNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        slow->next = prev;
        slow = slow->next;

        // Now from here I started comparing dummy data and slow data.
        SLLNode* dummy = head;

        while(slow){
            if(dummy->data != slow->data)
                return false;

            
            dummy = dummy->next;
            slow = slow->next;
        }

        // printList(head);

        return true;
}
};




int main(){

    SLLNode* head = NULL, *tail = NULL;
    Solution obj = Solution();

    obj.insertAtEnd(head, tail, 1);
    obj.insertAtEnd(head, tail, 2);
    obj.insertAtEnd(head, tail, 3);
    obj.insertAtEnd(head, tail, 3);
    obj.insertAtEnd(head, tail, 2);
    obj.insertAtEnd(head, tail, 4);

    obj.printList(head);
    cout<<"List Len: "<<obj.getListLen(head)<<endl;

    cout<<"List is : "<<obj.isPalindrome_optim(head)<<endl;
    


    return 0;
}
