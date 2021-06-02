#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int val){
    data=val;
    next=NULL;
    }
};
void insertList(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* n){

    while(n!=NULL){
        cout<<n->data<<"->";
        n=n->next;
    }cout<<"NULL"<<endl;
}
void insetHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
bool search(node* head,int data){
    node* n=head;
    while(n!=NULL){
        if(n->data==data){
            return true;
        }
        n=n->next;

    }return false;

}
void deletion(node* head,int data){
    node* n=head;
    while(n->next->data!=data){
        n=n->next;
    }
    node* todelete=n->next;
    n->next=n->next->next;
    delete todelete;

}
void deleteHead(node* &head){
    //node* n=head;
    node* todelete=head;
    head=head->next;
    delete todelete;
}
/*node* reverseList(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;

        prev=curr;curr=next;
    }
    return prev;
}*/
node* reverseList(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
void cyclic(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }temp->next=startNode;
}
bool checkLoop(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            {return true;}
            }return false;

}
void removeCycle(node* &head){
    node* fast=head;
    node* slow=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
        fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }slow->next=NULL;
}
int main(){
    node* head=NULL;
    insertList(head,1);
    insertList(head,2);
    insertList(head,3);
    insertList(head,4);
    insertList(head,5);
    insertList(head,6);
    insertList(head,7);
    insertList(head,8);
    insertList(head,9);
    display(head);
    insetHead(head,6);
    display(head);
    cout<<search(head,9)<<endl;
    deletion(head,5);
    display(head);
    deleteHead(head);
    display(head);
    /*node* n=reverseList(head);
    display(n);*/
    /*node* p=reverseList(head);
    display(p);*/
   cyclic(head,4);
   cout<<checkLoop(head)<<endl;
   removeCycle(head);
   display(head);
   cout<<checkLoop(head)<<endl;



}
