#include<iostream>
using namespace std;
class queue
{
	private:
	struct node
	{
		int data;
		node *link;
	}*front, *rear;
	public:
	queue();
	void add(int item);
	int del();
	~queue();
};
queue::queue()
{
	front = rear = NULL;
}
void queue::add(int item)
{
	node *temp;
	temp = new node;
	if(temp == NULL)
	{
		cout<<"\nQUeue is full";
		return;
	}
	temp->data = item;
	temp->link = NULL;
	if(front == NULL)
	{
		front = rear = temp;
	}
	rear->link = temp;
	rear = rear->link;
}
int queue::del()
{
	if(front==NULL)
	{
		cout<<"Queue is empty";
		return NULL;
	}
	node *temp;
	temp = front;
	int item = front->data;
	front = front->link;
	delete temp;
	return item;
}
queue::~queue()
{
	if(front == NULL)
	return;
	node *temp;
	while(front!=NULL)
	{
		temp = front;
		front = front->link;
		delete temp;
	}
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
        cout<<"\n"<<q.del();
    }
}
