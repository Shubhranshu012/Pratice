#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }    
};

void inserttail(int d,Node* &tail){
    // creating new node
    Node* temp = new Node(d);
    tail ->next=temp;
    tail=temp;
}

void inserthead(int d,Node* &head){
    Node *temp =head;

    Node* temp1=new Node(d);
    temp1 -> next = temp;
    head=temp1;

}

void middle(Node* &head,int d,int pos){
     
    
    Node* temp1 = head;
    int count=1;
    while(count<(pos-1)){
        temp1=temp1 ->next;
        count++;
    }
    Node* newtemp = new Node(d);
    newtemp -> next = temp1 -> next;
    temp1 -> next = newtemp;
    
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){
    Node* node1=new Node(10);
    Node* tail=node1;
    Node* head=node1;
    print(head);

    inserttail(20,tail);

    print(head);

    inserthead(50,head);
    print(head);

    middle(head,90,2);
    print(head);

return 0;
}
