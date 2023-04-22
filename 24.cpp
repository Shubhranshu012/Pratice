#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this -> data = d ;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void head1(int d, Node* &head){
    Node* temp=new Node(d);
    temp -> next = head;
    head-> prev=temp;
    head=temp;
}

void tail1(int d,Node* &tail){
    Node* temp=new Node(d);
    tail -> next = temp;
    temp->prev=tail;
    tail=temp;

}

void mid(Node* &tail, Node* &head,int pos, int d){

    if(head==NULL){
        head1(d,head);
        return;
    }
    else if(tail==NULL){
        tail1(d,tail);
        return;
    }

    Node* current=head;
    int count=1;
    while(count<(pos-1)){
        current=current->next;
    }
    Node* temp=new Node(d);
    temp->next=current->next;
    current->next->prev=temp;
    current->next=temp;
    temp->prev=current;

}

void print1(Node* &head){
    if(head==NULL){
        cout<<"Enpty list";
        return;
    }

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* value= new Node(20);
    Node* head = value;
    Node* tail = value;
    print1(head);

    head1(10,head);
    print1(head);

    tail1(30,tail);
    print1(head);

    mid(tail,head,2,40);
    print1(head);



    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    return 0;

}