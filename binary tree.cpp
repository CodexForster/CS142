#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node * parent;
		node * left;
		node * right;
		
	node()
	{ data=0;
	parent=NULL;
	left=NULL;
	right=NULL;
}
} *head;

void insert();
void search();
void deletenode();
int display(node * temp);



int main()
{
	int op1;
	char op2;
	do{
		cout<<"\nEnter option\n1)Insert\n2)Search\n3)Delete\n4)Dislay";
		cin>>op1;
		switch(op1)
		{
			case 1: insert();
				break;
			case 2: search();
				break;
			//case 3: deletenode();
			//	break;
			case 4: int a=display(head);
				break;
		}
	cout<<"\nRun again?";
	cin>>op2;
	}while(op2=='y');
	
	return 0;
	
}


void insert()
{
	int dat;
	cout<<"\nEnter data";
	cin>>dat;
	node* temp=new node;
	node *temp2=new node;
	temp2->data=dat;
	temp->data=dat;
	if(head==NULL)
	{head=temp;
	head->parent=NULL;
	head->left=NULL;
	head->right=NULL;}
	else
	{	temp=head;
		while(temp->left!=NULL||temp->right!=NULL)
		{
			if(temp->data>dat)
				temp=temp->left;
			else if(temp->data<dat)
				temp=temp->right;
			else if(temp->data=dat)
			{}
		}
		if(temp->data>dat)
			{temp->left=temp2;
			temp2->parent=temp;}
		else if(temp->data<dat)
			{temp->right=temp2;
			temp2->parent=temp;}
		}
		
}

int display(node * temp)
{
	if(temp==NULL)
	{return 0;}
	display(temp->left);
		cout<<temp->data;
	display(temp->right);
		//cout<<temp->data;
}
	

void search()
{int a;
cout<<"\nEnter the element you want to search";
cin>>a;
int b=1;
node *temp=new node;
temp=head;
while(temp->left!=NULL||temp->right!=NULL)
{
	if(temp->data>a)
		temp=temp->left;
	else if(temp->data<a)
		temp=temp->right;
	else if(temp->data==a)
		{b=0;
		break;}
}
if(b==0)
cout<<"\nThe node with data "<<a<<" is present";
else
cout<<"\nThe node with data "<<a<<" is not present";
}
