#include<iostream>
#include<curses.h>
#include<stdlib.h>
using namespace std;

//class definition
class StackLL
{public:
int data;
StackLL *next;
StackLL()
	{data=0;
	next=NULL;
	}
}*head,*tail;


//function prototypes
void push();
void pop();
void display();

//main start here
int main()
{int op1;
char op2;
do{
cout<<"\n1)Push\n2)Pop\n3)Display Stack";
cin>>op1;
switch(op1)
{	case 1: push();
		break;
	case 2: pop();
		break;
	case 3: display();
		break;
}
cout<<"\nRun again(y/n)";
cin>>op2;}while(op2=='y');

return 0;}

//function definitions start here
//function to push an object/element
void push()
{StackLL *temp=new StackLL;
int dat;
cout<<"\nEnter data";
cin>>dat;
temp->data=dat;
if(head==NULL)
	head=temp;
else{
	temp->next=head;
	head=temp;
	}
}

//function to delete/pop an object/element
void pop()
{StackLL *temp=new StackLL;
if(head==NULL)
	cout<<"\nNo elements present in the stack";
else{
	temp=head;
	temp=temp->next;
	head=temp;
	}
}


//function to display all elements/objects in the stack
void display()
{StackLL *temp = new StackLL;
if(head==NULL)
	cout<<"\nNo elements present in the stack";
else{   temp=head;
	while(temp!=NULL)
		{cout<<temp->data<<"-";
		temp=temp->next;}
	}
}