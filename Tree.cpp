#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
   
void postorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}
void inorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(node->left);
        cout << node->data <<" ";
        inorderTraversal(node->right);
    }
}

void preorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        cout << node->data << " ";
        inorderTraversal(node->left);
        inorderTraversal(node->right);
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    cout<<"hello"<<endl;

    cout << "Inorder Traversal"
         << " ";
    inorderTraversal(root);
    cout << endl;

    cout << "postorder Traversal"
         << " ";
    postorderTraversal(root);
    cout << endl;

    cout << "preorder Traversal"
         << " ";
    preorderTraversal(root);
    cout << endl;
}