#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

struct List
{
    Node *head, *tail;
    int length;

    List(){
        head = tail=NULL;
        length=0;
    }

    void display() {
        Node *temp=head;
        cout<<"List of "<<length<<" elements: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    Node* lastNode() {
        Node *temp=head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        return temp;
        
    }

    void addNodeToEnd(int data) {
        Node *node = new Node;
        node->data = data;
        node->next=NULL;
        node->prev = tail;

        if(head == NULL) {
            head = tail= node;
        } else {
            tail->next = node;
            tail = node;
        }
        length++;
    }
    void addNodeToStart(int data) {
        
        Node *node=new Node;
        node->data=data;
        node->next=head;
        node->prev=NULL;
        head=node;
        length++;
    }
    void addNodeToPositionn(int data, int position);

    void deleteNodeFromEnd(){
        if(length <= 0){
            cout<<"list is already empty";
            return;
        }
        Node *deleteThis = tail;
        tail=tail->prev;
        tail->next = NULL;
        delete deleteThis;
        length--;
    }
    void deleteNodeFromStart() {
        if(length <= 0){
            cout<<"list is already empty";
            return;
        }
        Node *deleteThis=head;
        head=head->next;
        head->prev=NULL;
        delete deleteThis;
        length--;
    }
    void deleteNodeFromPosition(int position);

    void deallocate() {
        Node *deleteThis, *temp = head;
        while(temp != NULL) {
            deleteThis = temp;
            temp = temp->next;
            delete deleteThis;
        }
    }
};

int main() {
    List list;
    list.addNodeToEnd(2);
    list.display();

    list.addNodeToEnd(3);
    list.display();

    list.addNodeToStart(1);
    list.display();

    list.deleteNodeFromStart();
    list.display();

    list.deleteNodeFromEnd();
    list.display();

    list.deallocate();
}
