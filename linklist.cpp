#include<iostream>
using namespace std;
class linklist
{
    private:
    struct node
    {
        int data;
        node * link;
    }*p;
    public:
    linklist();
    void addatend(int item);
    void addatbeg(int item);
    void addafter(int loc, int item);
    void display();
    int count();
    void del(int num);
    void delat(int loc);
    void reverse();
    ~linklist();
};
linklist::linklist()
{
    p = NULL;
}
void linklist::addatend(int item)
{
    node *temp, *r;
    if(p==NULL)
    {
        temp = new node;
        temp->data = item;
        temp->link = NULL;
    }
    else
    {
        temp = p;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        r = new node;
        r->data = item;
        r->link = NULL;
        temp->link = r;
    }
}
void linklist::addatbeg(int item)
{
    node *temp;
    temp = new node;
    temp->data = item;
    temp->link = p;
    p = temp;
}
void linklist::addafter(int loc, int item)
{
    node *temp, *r;
    temp =p;
    for(int i=0; i<loc; i++)
    {
        if(temp!=NULL)
        temp = temp->link;
        else
        {
            cout<<"The number of nodes are less than the location"<<loc<<" provided.";
            return;
        }
    }
    r = new node;
    r->data = item;
    r->link = temp->link;
    temp->link = r;
}
void linklist::reverse()
{
    node *q, *r, *s;
    q = p;
    r = NULL;
    while(q!=NULL)
    {
        s = r;
        r = q;
        q = q->link;
        r->link = s;
    }
    p = r;
}
void linklist::display()
{
    node *temp;
    temp = p;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}
int linklist::count()
{
    int counter=0;
    node *temp;
    while(temp!=NULL)
    {
        temp = temp->link;
        counter++;
    }
    return counter;
}
void linklist::del(int num)
{
    node *temp, *old;
    temp=p;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(temp==p)
            p = temp->link;
            else
            old->link = temp->link;
            delete temp;
            return;
        }
        else
        {
            old = temp;
            temp = temp->link;
        }
    }
}
void linklist::delat(int loc)
{
    node *temp, *old;
    temp = p;
    int counter=1;
    while(temp!=NULL)
    {
        if(counter<loc)
        {
            counter++;
            old = temp;
            temp = temp->link;
        }
        else
        {
            if(temp == p)
            p = temp->link;
            else
            old->link = temp->link;
            delete temp;
            return;
        }
    }
}
linklist::~linklist()
{
    node *q;
    while(p!=NULL)
    {
        q = p->link;
        delete p;
        p = q;
    }
}
int main()
{
    linklist l;
    for(int i = 0; i<20; i++)
    {
        l.addatbeg(i+1);
    }
    l.reverse();
    l.display();
    cout<<endl;
    for(int i = 1; i<=10; i=i++)
    {
        l.delat(i+1);
    }
    cout<<endl;
    l.display();
}
