#include<iostream>
using namespace std;
const int MAX= 10;
class circqueue
{
    private:
    int arr[MAX];
    int front, rear;
    public:
    circqueue();
    void addcirc(int item);
    int del();
    void display();
};
circqueue::circqueue()
{
    front = rear = -1;
    for(int i = 0; i<MAX; i++)
    {
        arr[i]=0;
    }
}
void circqueue::addcirc(int item)
{
    if(((rear==MAX-1)&&(front==-1))||(rear+1==front))
    {
        cout<<"\nQueue is full";
        return;
    }
    if(rear==MAX-1)
    rear=0;
    else
    rear++;
    arr[rear] = item;
    if(front==-1)
    front =0;
}
int circqueue::del()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty";
        return NULL;
    }
    int item;
    item = arr[front];
    arr[front] = 0;
    if(front==rear)
    {
        front = rear = -1;
    }
    else
    {
        if(front == MAX -1)
        front = 0;
        else
        front++;
    }
    return item;
}
void circqueue::display()
{
    cout<<endl;
    for( int i =0; i < MAX ; i++ )
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    circqueue a;
    int i;
    for(int i=0; i<10; i++)
    {
        a.addcirc(i+1);
    }
    a.display();
    for(i=0; i<8; i++)
    {
        a.del();
    }
    a.display();

}
