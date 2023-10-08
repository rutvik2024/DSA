#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

        // Constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // Destructor
        ~Node(){
            int val = this->data;

            // Memory Free code
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }

            cout<<"Node with value "<<val<<" deleted successfully..!!"<<endl;
        }

};


class Solution{
    public:

        // Driver function start

        void insertBegin(Node* &head, Node* &tail, int data){
            Node *temp = new Node(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }
            temp->next = head;
            head = temp;
        }

        void printList(Node* &head){
            Node* temp = head;

            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }

            cout<<endl;
        }

        // Driver function end

        // Brute force approach 
        // Time Complexity: O(k*n)
        // space complexity: O(1)

        Node* rotateList_brute(Node* head, int k){
            
            // List is empty or contain single node
            if(head == NULL || head->next == NULL)
                return head;

            // List is not empty and contain atleast 2 nodes
            for(int i = 0; i<k; i++){
                Node* temp = head;

                while(temp->next->next != NULL)
                    temp = temp->next;
                
                temp->next->next = head;
                head = temp->next;
                temp->next = NULL;
            }

            return head;
        }



        // Btter approach Using Array
        // Time Complexity: O(3*n)
        // space complexity: O(n)

        Node *rotateList_better(Node *head, int k) {
            if(head == NULL)
                return head;

            vector<int> arr;

            Node* temp = head;
            // Insert all list element to array
            while(temp){
                arr.push_back(temp->data);
                temp = temp->next;
            }

            cout<<"Vector elements are: ";
            for(auto it:arr)
                cout<<it<<" ";
            cout<<endl;


            // Rotate element by k in array
            int n = arr.size();

            reverse(arr.begin(), arr.end());

            reverse(arr.begin(), arr.begin()+k);

            reverse(arr.begin() + k, arr.end());

            // int curri = 0, currv = arr[curri];
            // for(int i = 0; i<n; i++){
            //     cout<<"Curr i: "<<curri<<endl;
            //     cout<<"Curr v: "<<currv<<endl;

            //     int newi = (curri + k)%n; // gives me target index
            //     cout<<"New i : "<<newi<<endl;
            //     int newv = arr[newi]; // store target index value
            //     cout<<"New v :"<<newv<<endl;
            //     arr[newi] = currv;
            //     curri = newi;
            //     currv = newv;

            //     cout<<"--------------------------------------------------------------------"<<endl;

            //     cout<<"After "<<i<<"th rotation Vector elements are: ";
                // for(auto it:arr)
                //     cout<<it<<" ";
                // cout<<endl;

            //     cout<<"--------------------------------------------------------------------"<<endl;
            // }


            
            // Insert all element one by one in list

            temp = head;
            for(auto it: arr){
                temp->data = it;
                temp = temp->next;
            }

            return head;
        }


};

int main(){

    Solution obj = Solution();

    Node* head = NULL, *tail = NULL;
    obj.insertBegin(head, tail, 6);
    obj.insertBegin(head, tail, 5);
    obj.insertBegin(head, tail, 4);
    obj.insertBegin(head, tail, 3);
    obj.insertBegin(head, tail, 2);
    obj.insertBegin(head, tail, 1);

    cout<<"Original List: ";
    obj.printList(head);

    int k;
    cin>>k;

    cout<<"After rotation List: ";
    head = obj.rotateList_better(head, k);
    obj.printList(head);


    return 0;
}