#include <iostream>
#include <conio.h>
using namespace std;
int stack[100], n = 100, top = -1;
int push(int data)
{
    if (top >= n - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = data;
    }
    
}
void pop()
{
    if (top <= -1)
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        cout << "The Popped element is " << stack[top] << endl;
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        cout << "stack element are:"<<endl;
        for (int i = top; i >= 0; i--)
            
            cout << stack[i]<<endl;
            
        
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}