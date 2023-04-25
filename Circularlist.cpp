#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this->data= d;
            this->next=NULL;
        }
};  

void head1(Node* &tail,int d){
    if(tail==NULL){
        Node* newnode=new Node(d);
        newnode -> next=newnode;
        tail = newnode;
        return;
    }
        Node* temp=new Node(d);
        temp->next=tail->next;
        tail->next=temp;
    
    
}

void tail1(Node* &tail, int d){
    if(tail==NULL){
        Node* newnode=new Node(d);
        newnode->next=newnode;
        tail=newnode;
        return;
    }


    Node* temp=new Node(d);
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;

}

void print1(Node* &tail){
    
    if(tail==NULL){
        cout<<"Enpty list";
        return;
    }
    int d=tail->data;
    do{
        tail=tail->next;
        cout<<tail->data<<" ";
    }while(tail->data != d);

    cout<<endl;
}

void mid(Node* &tail,int pos,int d){
    if(tail==NULL){
        head1(tail,d);
        return;
    }
    if(pos==1){
        head1(tail,d);
        return;
    }
    Node* val=tail;
    
    int count=1;
    while(count<pos){
        val=val->next;
        count++;
    }
    Node* temp=new Node(d);
    temp->next=val->next;
    val->next=temp;

}

int main(){
    Node* node1=NULL;
    Node*tail=node1;


    head1(tail,10);
    print1(tail);

    head1(tail,20);
    print1(tail);

    head1(tail,30);
    print1(tail);
    
    tail1(tail,40);
    print1(tail);


    mid(tail,2,50);
    print1(tail);

    mid(tail,3,70);
    print1(tail);


    return 0;
}
