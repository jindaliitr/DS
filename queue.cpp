#include<iostream>
using namespace std;
const int MAX=10;
class queue
{
    private:
    int arr[MAX];
    int front, rear;
    public:
    queue();
    void add(int item);
    int del();
};
queue::queue()
{
    front=rear=-1;
}
void queue::add(int item)
{
    if(rear==MAX-1)
    {
        cout<<"\nQueue is full";
        return;
    }
    rear++;
    arr[rear]=item;
    if(front==-1)
    front =0;
}
int queue::del()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty";
        return NULL;
    }
    int item = arr[front];
    arr[front]=NULL;
    if(front==rear)
    front= rear=-1;
    else
    front++;
    return item;
}
int main()
{
    int n;
    queue q;
    for(int i=0; i<11; i++)
    {
        q.add(i+1);
    }

    for(int i=0; i<11; i++)
    {
        cout<<q.del()<<"\n";
    }
}
