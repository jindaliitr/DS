#include<iostream>
using namespace std;
class stack
{

    private:
    struct node
    {
        int data;
        node *link;
    }*top;
    public:
    stack();
    void push(int item);
    int pop();
    ~stack();
};
stack::stack()
{
    top=NULL;
}
void stack::push(int item)
{
    node *temp;
    temp = new node;
    if(temp == NULL)
    {
        cout<<"\nStack is full";
    }
    temp->data= item;
    temp->link= top;
    top=temp;
}
int stack::pop()
{
    if(top==NULL)
    {
        cout<<"\nStack is empty";
        return NULL;
    }
    node *temp;
    int item;
    temp = top;
    item = temp->data;
    top = top->link;
    delete temp;
    return item;
}
stack::~stack()
{
    if(top==NULL)
    {
        return;
    }
    node *temp;
    while(top!=NULL)
    {
        temp = top;
        top = top->link;
        delete temp;
    }
}
int main()
{
    int n;
    stack s;
    for(int i=0; i<110; i++)
    {
        s.push(i+1);
    }
    for(int i=0; i<11; i++)
    {
        cout<<s.pop()<<"\n";
    }
}
