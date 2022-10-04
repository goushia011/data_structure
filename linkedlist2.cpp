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
        if (position > length + 1)
        {
            cout << "Insertion failed! Position out of bound" << endl;
            return;
        }
        if (position == 1)
        {
            cout << "adding to start";
            addNodeToStart(data);
            return;
        }
        if (position == length + 1)
        {
            cout << "adding to end";
            addNodeToEnd(data);
            return;
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

        node->prev->next = node;
        temp->prev = node;
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
    void deleteNodeFromPosition(int position)
    {
        if (position > length)
        {
            cout << "Deletion failed! " << endl;
            return;
        }
        if (position == 1)
        {
            deleteNodeFromStart();
            return;
        }
        if (position == length)
        {
            deleteNodeFromEnd();
            return;
        }
        Node *temp = head, *deleteThis;
        while (position-- > 1)
        {
            temp = temp->next;
        }
        deleteThis = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete deleteThis;
    }

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
