#include<iostream>
using namespace std;
const int MAX= 10;
class stack
{
    private:
    int arr[MAX];
    int top;
    public:
    stack();
    void push(int item);
    int pop();
    int peep();
    void update(int value);
};
stack::stack()
{
    top=-1;
}
void stack::push(int item)
{
    if(top==MAX-1)
    {
        cout<<"\nStack is full for the element "<<item;
        return;
    }
    top++;
    arr[top]=item;
}
int stack::pop()
{
    if(top==-1)
    {
        cout<<"\nStack is empty ";
        return NULL;
    }
    int data= arr[top];
    arr[top]= NULL;
    top--;
    cout<<"\nPopped element is : ";
    return data;
}
int stack::peep()
{
    return arr[top];
}
void stack::update(int value)
{
    arr[top]=value;
}
int main()
{
    int n;
    stack s;
    for(int i=0; i<11; i++)
    {
        s.push(i+1);
    }
    cout<<"\nTop of the stack is : "<<s.peep();
    s.update(20);
    cout<<"\nTop of the stack is : "<<s.peep();
    for(int i=0; i<11; i++)
    {
        cout<<s.pop();
    }
}
