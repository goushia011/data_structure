#include <iostream>
#include "linkedlist2.cpp"
using namespace std;
struct Queue : List
{
    void insert(int data)
    {
        addNodeToEnd(data);
    }
    void remove()
    {
        deleteNodeFromStart();
    }
    void display()
    {
        cout << "Queue of " << length << " elements" << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Queue queue;
    queue.insert(1);
    queue.insert(2);
    queue.insert(3);
    queue.remove();
    queue.display();

    queue.deallocate();
}
