#include<iostream>
#include "linkedlist2.cpp"

struct Stack : List {
    void push(int data) {
        addNodeToEnd(data);
    }

    void pop() {
        deleteNodeFromEnd();
    }

    void display() {
        cout<<"Stack of "<<length<<" elements"<<endl;
        Node *temp = tail;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp = temp->prev;
        }
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.display();

    stack.deallocate();

}