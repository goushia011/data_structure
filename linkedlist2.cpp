#include <iostream>
using namespace std;

struct Node
{
    int data, position;
    Node *next, *prev;
};

struct List
{
    Node *head, *tail;
    int length;

    List()
    {
        head = tail = NULL;
        length = 0;
    }

    void display()
    {
        Node *temp = head;
        cout << "List of " << length << " elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *lastNode()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }

    void addNodeToEnd(int data)
    {
        Node *node = new Node;
        node->data = data;
        node->next = NULL;
        node->prev = tail;

        if (length == 0)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        length++;
    }
    void addNodeToStart(int data)
    {

        Node *node = new Node;
        node->data = data;
        node->next = head;
        node->prev = NULL;

        if (length == 0)
        {
            head = tail = node;
        }
        else
        {
            head = node;
        }

        length++;
    }
    void addNodeToPosition(int data, int position)
    {
        if (position > length + 1) {
            cout<<"Insertio failed! Position out of bound"<<endl;
            return;
        }
        if(position == 1) {
            addNodeToStart(data);
        }
        if(position == length + 1) {
            addNodeToEnd(data);
        }
        Node *temp = head;
        while (position-- > 1)
        {
            temp = temp->next;
        }
        Node *node = new Node;
        node->data = data;
        node->prev = temp->prev;
        node->next = temp;
        temp = temp->next;
    }

    void deleteNodeFromEnd()
    {
        if (length <= 0)
        {
            cout << "list is already empty";
            return;
        }
        Node *deleteThis = tail;
        if (length == 1)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete deleteThis;
        length--;
    }
    void deleteNodeFromStart()
    {
        if (length <= 0)
        {
            cout << "list is already empty";
            return;
        }
        Node *deleteThis = head;

        if (length == 1)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete deleteThis;
        length--;
    }
    void deleteNodeFromPosition(int position);

    void deallocate()
    {
        Node *deleteThis, *temp = head;
        while (temp != NULL)
        {
            deleteThis = temp;
            temp = temp->next;
            delete deleteThis;
        }
    }
};

int main()
{
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

    list.addNodeToPosition(5, 2);
    list.display();

    list.deallocate();
}
