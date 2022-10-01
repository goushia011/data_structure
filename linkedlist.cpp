#include <iostream>
#include <conio.h>
using namespace std;

struct List
{
    int value;
    List *next;
    void display()
    {
        List temp = *this;
        cout << "value : " << temp.value << endl;
        while (temp.next != NULL)
        {
            temp = *(temp.next);
            cout << "value : " << temp.value << endl;
        }
    }
    
    List* lastNode()
    {
        List *temp = this;
        while (true)
            if (temp->next == NULL)
                return temp;
            else
                temp = temp->next;
    }

    List addNode(int value) {
        List *newNode = new List;
        newNode->value = value;
        newNode->next = NULL;
        List *lastNode = this->lastNode();
        lastNode->next = newNode;
        return *newNode;
    }

    void deleteLast(){
        List *temp=this;
        List *temp1;
        while(temp != NULL)
        {
            if(temp->next->next == NULL) {
                temp1 = temp->next;
                temp->next=NULL;
                delete temp1;
                temp = NULL;
            }
            else {
                temp = temp->next;
            }
        }
    }

    List* deleteFirst();

    void DestroyList() {
        List temp = *this;
        List *deleteThis;
        while (temp.next != NULL) {
            deleteThis = &temp;
            temp = *(temp.next);
            delete deleteThis;
        }
    }
};

int main()
{
    List list;
    list.value = 1;
    List node;
    node.value = 2;
    node.next = NULL;
    list.next = &node;

    list.display();
    List *newNode;
    newNode = new List;

    newNode->value = 3;
    newNode->next = NULL;
    node.next = newNode;
    list.display();

    List last = list.addNode(4);
    list.display();
    list.deleteLast();
    list.display();
    list.deleteLast();
    list.display();

    // list.DestroyList();

}
