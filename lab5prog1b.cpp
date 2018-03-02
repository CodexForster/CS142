#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};


class list
{
	private:
	node *head, *tail;//declaring head and tail of the list
	
	public:
	list()
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;//a single unliked node has been created
		if(tail==NULL)//case of an empty list
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}


	void bubblesort()
	{
		int b=countitems();
		node *p=new node;
		node *q=new node;
		node *t=new node;
	for(int i=0;i<b;i++)
	{
		p=head;;
		q=head->next;
	for(int j=0;j<b-1;j++)
	{
		if(p->data>q->data)                         //Comparing the adjacent two elemnts of the list
		{                                    //and swapping them in ascending order
			t->data=p->data;                 //and this is iterated for every node
			p->data=q->data;             //And this way the list is processed n(no of node) times
			q->data=t->data;
		}
		p=p->next;
		q=q->next;
		
	}
	}
}

	void display()
	{
		node *temp=new node;
		temp=head;
		while(temp->next!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
					}
		cout<<temp->data<<"->NULL";
	}




int countitems()
{	
	int i=0;
	node *temp=new node;
	temp=head;
	while(temp->next!=NULL)
	{i=i+1;
	temp=temp->next;}
	return i+1;//since the tail element is not counted, i is incremented by 1
}
};

int main() {
	list a;
	int c=0,val=0;
	cout<<"\n Enter the no of elements in the list";
	cin>>c;
	for(int i=0;i<c;i++)
	{
		cout<<"\n Enter the #"<<i+1<<" element :";
		cin>>val;
		a.insert(val);
	}
	cout<<"\n The original list is:";
	a.display();
	a.bubblesort();
	cout<<"\n The sorted list is:";
	a.display();
	return 0;
}
