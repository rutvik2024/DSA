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

};

class Uitlity{
    public:
        void insertBegin(Node* &head, int data){
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        void insertEnd(Node* &head, Node* &tail, int data){
            Node *temp = new Node(data);
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

};

class Solution{
    public:
    Node* sortTwoLists(Node* &h1, Node* &h2){
        Uitlity utils = Uitlity();
        Node* ans = NULL, *tail = NULL;
        Node* t1 = h1, *t2 = h2;

        while(t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                utils.insertEnd(ans, tail, t1->data);
                t1 = t1->next;
            }

            else{
                utils.insertEnd(ans, tail, t2->data);
                t2 = t2->next;
            }
        }

        while(t1 != NULL){
            utils.insertEnd(ans, tail, t1->data);
            t1 = t1->next;
        }

        while(t2 != NULL){
            utils.insertEnd(ans, tail, t2->data);
            t2 = t2->next;
        }

        return ans;
    }

    Node* sortTwoLists_inplace(Node* h1, Node* h2){
        if(h1 == NULL)
            return h2;

        if(h2 == NULL)
            return h1;

        if(h1->data > h2->data)
            swap(h1, h2);

        Node* res = h1;

        while(h1 != NULL && h2 != NULL){
            Node* temp = NULL;

            while(h1 != NULL && h1->data <= h2->data){
                temp = h1;
                h1 = h1->next;
            }

            temp->next = h2;
            swap(h1, h2);
        }

        return res;
    }

    Node* sortTwoLists_rec(Node* h1, Node* h2){
        if(h1 == NULL) return h2;
    
        if(h2 == NULL) return h1;

        if(h1->data < h2->data){
            h1->next = sortTwoLists_rec(h1->next, h2);
            return h1;
        }

        else{
            h2->next = sortTwoLists_rec(h1, h2->next);
            return h2;
        }
    }
};

int main(){
    Uitlity util = Uitlity(); // Utility class for insertion and printing purpose
    Solution sol = Solution();


    Node* h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    cout<<"First List : \n";
    util.insertEnd(h1, t1, 10);
    util.insertEnd(h1, t1, 20);
    util.insertEnd(h1, t1, 30);
    util.insertEnd(h1, t1, 40);
    util.printList(h1);


    cout<<"Second List : \n";
    util.insertEnd(h2, t2, 5);
    util.insertEnd(h2, t2, 5);
    util.insertEnd(h2, t2, 35);
    util.insertEnd(h2, t2, 45);
    util.insertEnd(h2, t2, 50);
    util.printList(h2);

    cout<<"Final List : \n";
    Node* ans = sol.sortTwoLists(h1, h2);

    util.printList(ans);

    return 0;
}