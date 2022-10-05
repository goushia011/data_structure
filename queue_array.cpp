#include<iostream>
#include<conio.h>
using namespace std;
class Queue{
    int data[100],tail, size;
    public:
    Queue(){
        tail=-1;
        size=100;
    }
    void display(){
        if(tail == -1){
            cout<<"queue is empty";
            return;
        }
        cout<<"queue element are:"<<endl;
        for(int i=0;i<=tail;i++){
            cout<<data[i]<<" ";
        }
    }

    int insert(int data){
        this->data[++tail] = data;
        
    }
    void remove(){
        if(tail == -1){
            cout<<"queue is empty";
            return;
        }
        for(int i=1;i<=tail;i++){
            data[i-1]=data[i];
        }
        tail--;
    }
};
int main() {
    int a[4];
    cout<<a[2];
    Queue queue;
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);
    queue.display();
    queue.remove();
    queue.remove();
    queue.remove();
    queue.remove();
    queue.display();


}