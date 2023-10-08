#include<bits/stdc++.h>
using namespace std;


class SLLNode{
    public:
        int data;
        SLLNode* next;

        // Constructor
        SLLNode(int data){
            this->data = data;
            this->next = NULL;
        }

        // Destructor
        ~SLLNode(){
            int val = this->data;

            // Memory Free code
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }

            cout<<"SLLNode with value "<<val<<" deleted successfully..!!"<<endl;
        }

};

class UtilSinglyList{

    public:
        void insertBegin(SLLNode* &head, SLLNode* &tail, int data){
            SLLNode *temp = new SLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }
            temp->next = head;
            head = temp;
        }

        void insertEnd(SLLNode* &head, SLLNode* &tail, int data){
            SLLNode *temp = new SLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }

            tail->next = temp;
            tail = temp;
        }

        void insertionAfterGivenPosition(SLLNode* &head, SLLNode* &tail, int pos, int data){

            if(pos == 1){
                insertBegin(head, tail, data);
                return;
            }


            SLLNode* temp = head;
            int count = 1;

            while(count < pos-1){
                count++;
                temp = temp->next;
            }

            if(temp->next == NULL){
                insertEnd(head, tail, data);
                return;
            }

            SLLNode* newSLLNode = new SLLNode(data);
            newSLLNode->next = temp->next;
            temp->next = newSLLNode;
            
        }

        void deletionSLLNode(SLLNode* &head, SLLNode* &tail, int pos){
            SLLNode* temp = head;
            // First SLLnode deletion
            if(pos == 1){
                head = head->next;
                temp->next = NULL;
                delete temp;
                return;
            }


            int count = 1;
            
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            
            // Middle SLLnode deletion
            if(temp->next != tail){
                SLLNode* p = temp->next;
                temp->next = temp->next->next;
                p->next = NULL; 
                delete p;
                return;
            }

            // last SLLnode deletion
            SLLNode* p = temp->next;
            temp->next = NULL;
            tail = temp;
            // p->next = NULL;
            delete p;
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
};
// ------------------------------------------------------------------------------------------------------------------------------------------------

class DLLNode{
    public:
        int data;
        DLLNode *next;
        DLLNode *prev;

        DLLNode(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~DLLNode(){
            int val = this->data;
            if(this->next){
                delete next;
                next = NULL;
            }

            cout<<"Memory node "<<val<<" deleted successfully..!!"<<endl;
        }
};

class UtilDoublyList{
    public:
        void insertAtHead(DLLNode* &head, DLLNode* &tail, int data){
            DLLNode* temp = new DLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                return;
            }

            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }

        void insertAtTail(DLLNode* &head, DLLNode* &tail, int data){
            DLLNode* temp = new DLLNode(data);
            if(tail == NULL){
                head = temp;
                tail = temp;
                return;
            }

            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            return;

        }

        void insertAtPosition(DLLNode* &head, DLLNode* &tail, int pos, int data){
            if(pos == 1 && head == NULL){
                DLLNode* temp = new DLLNode(data);
                head = temp;
                tail = temp;
                return;
            }

            if(pos == 1){
                insertAtHead(head, tail, data);
                return;
            }

            int count = 1;
            
            DLLNode* temp = head;
            while(count < pos-1){
                count++;
                temp = temp->next;
            }

            // If insert at end
            if(temp == tail){
                insertAtTail(head, tail, data);
                return;
            }

            // If insert at middle
            DLLNode* newNode = new DLLNode(data);
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }

        void deletionDLLNode(DLLNode* &head, DLLNode* &tail, int pos){
            DLLNode* temp = head;
            // First DLLnode deletion
            if(pos == 1){
                head = head->next;
                head->prev = NULL;
                temp->next = NULL;
                delete temp;
                return;
            }


            int count = 1;
            
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            
            // Middle DLLnode deletion
            if(temp->next != tail){
                DLLNode* p = temp->next;
                temp->next = temp->next->next;
                p->next = NULL; 
                delete p;
                return;
            }

            // last DLLnode deletion
            DLLNode* p = temp->next;
            temp->next = NULL;
            tail = temp;
            // p->next = NULL;
            delete p;
            return;
        }

        void printDList(DLLNode* &head){
            DLLNode* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
// ------------------------------------------------------------------------------------------------------------------------------------------------

class UtilCircularSLL{

    public:
        void insertBegin(SLLNode* &head, SLLNode* &tail, int data){
            SLLNode *temp = new SLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                temp->next = temp;
                return;
            }
            temp->next = head;
            head = temp;
            tail->next = head;
            return;
        }

        void insertEnd(SLLNode* &head, SLLNode* &tail, int data){
            SLLNode *temp = new SLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                temp->next = temp;
                return;
            }

            temp->next = head;
            tail->next = temp;
            tail = temp;
            return;
        }

        void insertionAfterGivenPosition(SLLNode* &head, SLLNode* &tail, int pos, int data){

            if(pos == 1){
                insertBegin(head, tail, data);
                return;
            }


            SLLNode* temp = head;
            int count = 1;

            while(count < pos-1){
                count++;
                temp = temp->next;
            }

            if(temp == tail){
                insertEnd(head, tail, data);
                return;
            }

            SLLNode* newSLLNode = new SLLNode(data);
            newSLLNode->next = temp->next;
            temp->next = newSLLNode;
        }

        void deletionSLLNode(SLLNode* &head, SLLNode* &tail, int pos){
            SLLNode* temp = head;
            // First SLLnode deletion
            if(pos == 1){
                head = head->next;
                tail->next = head;
                temp->next = NULL;
                delete temp;
                return;
            }


            int count = 1;
            
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            
            // cout<<"\nTemp data: "<<temp->data<<endl;
            // Middle SLLnode deletion
            if(temp->next != tail){
                SLLNode* p = temp->next;
                temp->next = temp->next->next;
                p->next = NULL; 
                delete p;
                return;
            }

            // cout<<"\nTemp data: "<<temp->data<<endl;
            // last SLLnode deletion
            SLLNode* p = temp->next;
            temp->next = head;
            tail = temp;
            p->next = NULL;
            delete p;
            return;
        }

        void printList(SLLNode* &head, SLLNode* &tail){
            SLLNode* temp = head;
            while(temp != tail){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data;
            cout<<endl;
        }
};

class UtilCircularDLL{
    
    public:
    void insertAtHead(DLLNode* &head, DLLNode* &tail, int data){
            DLLNode* temp = new DLLNode(data);
            if(head == NULL){
                head = temp;
                tail = temp;
                temp->next = head;
                temp->prev = head;
                return;
            }

            temp->next = head;
            head->prev = temp;
            head = temp;
            temp->prev = tail;
            tail->next = temp;
            return;
        }

        void insertAtTail(DLLNode* &head, DLLNode* &tail, int data){
            DLLNode* temp = new DLLNode(data);
            if(tail == NULL){
                head = temp;
                tail = temp;
                return;
            }

            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            tail->next = head;
            head->prev = tail;
            return;

        }

        void insertAtPosition(DLLNode* &head, DLLNode* &tail, int pos, int data){
            if(pos == 1 && head == NULL){
                DLLNode* temp = new DLLNode(data);
                head = temp;
                tail = temp;
                temp->next = head;
                temp->prev = head;
                return;
            }

            if(pos == 1){
                insertAtHead(head, tail, data);
                return;
            }

            int count = 1;
            
            DLLNode* temp = head;
            while(count < pos-1){
                count++;
                temp = temp->next;
            }

            // If insert at end
            if(temp == tail){
                insertAtTail(head, tail, data);
                return;
            }

            // If insert at middle
            DLLNode* newNode = new DLLNode(data);
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }

        void deletionDLLNode(DLLNode* &head, DLLNode* &tail, int pos){
            DLLNode* temp = head;
            // First DLLnode deletion
            if(pos == 1){
                head = head->next;
                head->prev = tail;
                tail->next = head;
                temp->next = NULL;
                delete temp;
                return;
            }


            int count = 1;
            
            while(count < pos-1){
                temp = temp->next;
                count++;
            }
            
            // Middle DLLnode deletion
            if(temp->next != tail){
                DLLNode* p = temp->next;
                temp->next = temp->next->next;
                p->next = NULL; 
                delete p;
                return;
            }

            // last DLLnode deletion
            DLLNode* p = temp->next;
            temp->next = head;
            tail = temp;
            head->prev = tail;
            p->next = NULL;
            delete p;
            return;
        }

        void printDList(DLLNode* &head, DLLNode* &tail){
            DLLNode* temp = head;
            while(temp != tail){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data;
            cout<<endl;
        }
};
// ------------------------------------------------------------------------------------------------------------------------------------------------


int main(){


    // // Singly Linked List
    // UtilSinglyList obj = UtilSinglyList();
    // SLLNode* head = NULL;
    // SLLNode* tail = NULL;
    // obj.insertBegin(head, tail, 10);
    // obj.insertBegin(head, tail, 20);
    // obj.insertBegin(head, tail, 30);
    // obj.printList(head);


    // SLLNode* h1 = NULL, *t1 = NULL;
    // obj.insertEnd(h1, t1, 10);
    // obj.insertEnd(h1, t1, 20);
    // obj.insertEnd(h1, t1, 30);
    // obj.printList(h1);

    // int pos;
    // cin>>pos;
    // // obj.insertionAfterGivenPosition(h1, t1, pos, 15);
    // // obj.printList(h1);

    // obj.deletionSLLNode(h1, t1, pos);
    // obj.printList(h1);
    // cout<<"Head :"<<h1->data<<endl;
    // cout<<"Tail:"<<t1->data<<endl;

    
    // // Doubly Linked List
    // DLLNode *dhead = NULL, *dtail = NULL;
    // UtilDoublyList dobj = UtilDoublyList();

    // dobj.insertAtHead(dhead, dtail, 10);
    // dobj.insertAtHead(dhead, dtail, 20);
    // dobj.insertAtHead(dhead, dtail, 30);
    // dobj.insertAtTail(dhead, dtail, 40);
    // dobj.printDList(dhead);

    // int pos;
    // cin>>pos;
    // // dobj.insertAtPosition(dhead, dtail, pos, 15);
    // dobj.deletionDLLNode(dhead, dtail, pos);
    // dobj.printDList(dhead);

    // cout<<"Head : "<<dhead->data<<endl;
    // cout<<"tail: "<<dtail->data<<endl;


    // // Circular Singly Linked List
    // UtilCircularSLL csobj = UtilCircularSLL();
    // SLLNode *chead = NULL, *ctail = NULL;
    // csobj.insertBegin(chead, ctail, 10);
    // csobj.insertBegin(chead, ctail, 20);
    // csobj.insertBegin(chead, ctail, 30);
    // csobj.insertEnd(chead, ctail, 40);
    // csobj.insertEnd(chead, ctail, 50);
    // csobj.printList(chead, ctail);
    // int pos;
    // cin>>pos;
    // // csobj.insertionAfterGivenPosition(chead, ctail, pos, 15);
    // csobj.deletionSLLNode(chead, ctail, pos);
    // csobj.printList(chead, ctail);

    // cout<<"Head: "<<chead->data<<endl;
    // cout<<"Tail: "<<ctail->data<<endl;


    // // Circular Doubly Linked List
    UtilCircularDLL cdobj = UtilCircularDLL();
    DLLNode *dhead = NULL, *dtail = NULL;
    cdobj.insertAtHead(dhead, dtail, 10);
    cdobj.insertAtHead(dhead, dtail, 20);
    cdobj.insertAtHead(dhead, dtail, 30);
    cdobj.insertAtTail(dhead, dtail, 40);
    cdobj.printDList(dhead, dtail);

    int pos;
    cin>>pos;
    // cdobj.insertAtPosition(dhead, dtail, pos, 15);
    cdobj.deletionDLLNode(dhead, dtail, pos);
    cdobj.printDList(dhead, dtail);

    cout<<"Head : "<<dhead->data<<endl;
    cout<<"Tail : "<<dtail->data<<endl;

    return 0;
}