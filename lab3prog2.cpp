/*Program Code for Assignment : Lab 3
Please note that this code was written in TurboC++ and i just changed the header files to 
make it run in g++(Linux)...(i dont't have Linux so i tested it on Ideone)
Worst Case if this code doesn't work : The main code is also in a multi-line comment at the end. */ 

#include<iostream>
#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class node{
public:
int data;
node * next;
node(){
data=0;
next=NULL; }
}*head,*tail;

void insert();
void insertAt();
void deletenode();
void deleteAt(int pos);
int countItems();
void display();

int main()
{int op;
char op2;
do{
cout<<"Enter Option\n1)Add Node at End of List\n2)Insert node at position\n3)Delete last node\n4)Delete node at a position\n5)Count number of items in the List\n6)Display List\n";
cin>>op;
switch(op)
{case 1:insert();
	break;
case 6: display();
	break;
case 2: insertAt();
	break;
case 3: deletenode();
	break;
case 4: {int pos;
	cout<<"\nEnter node position";
	cin>>pos;
	deleteAt(pos);}
	break;
case 5: {cout<<"\nThere are "<<countItems()<<" nodes present in the list.";}
	break;
};
cout<<"\nRun Again?";
cin>>op2;
}while(op2=='y');
return 0;}

void insert()
{node *temp=new node;
int d;
cout<<"\nEnter data";
cin>>d;
if(head==NULL)
	{temp->data=d;
	head=temp;
	tail=temp;
	}
else{
	temp->data=d;
	tail->next=temp;
	tail=temp;
	tail->next=head;}
}


void insertAt()
{node *temp=new node,*temp2=new node,*temp3= new node;
temp2=head;
int d,pos,count=1;
cout<<"Enter data and position of insertion" ;
cin>>d>>pos;
temp->data=d;
if(countItems()<(pos-1))
	cout<<"Linked List does not have that many elements";
else if(pos==1)
	{temp->next=head;
	head=temp;
	tail->next=head;}
else if(countItems()==pos-1)
	{tail->next=temp;
	tail=temp;
	tail->next=head;}
else{
	while(count!=pos-1)
		{temp2=temp2->next;
		++count;}
	temp3=temp2->next;
	temp2->next=temp;
	temp->next=temp3;}
}


void deletenode()
{node *temp=new node;
temp=head;
if(head==NULL)
	cout<<"\nNo nodes present.";
else
	{node *temp=new node;
	temp=head;
	while(temp->next!=tail)
		temp=temp->next;
	temp->next=head;
	tail=temp;
	tail->next=head;
}
}

void deleteAt(int pos)
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
	{cout<<"\nNo nodes present.";}
else if(pos>countItems())
	{cout<<"\nLinked List does not have that many nodes present."; }
else if(pos==1)
	{head=head->next;
	tail->next=head;}
else if(pos==countItems())
	{deletenode(); }
else{
	while(count!=pos-1)
	{temp=temp->next;
	++count;}
	node *temp2=new node;
	temp2=(temp->next)->next;
	temp->next=temp2;
    }
}

int countItems()
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
	{cout<<"\nNo nodes present.";
	return 0;}
else
	{while(temp!=tail)
		{temp=temp->next;
		++count;}
	return (count);
}
}


void display()
{if(head==NULL)
cout<<"\nNo Nodes present.";
else{
	node *temp=new node;
	temp=head;
	while(temp!=tail)
		{cout<<temp->data<<"->";
		temp=temp->next;
		}
	cout<<tail->data<<"->";
	cout<<"Head...";
	}
}




/*
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

class node{
public:
int data;
node * next;
node(){
data=0;
next=NULL; }
}*head,*tail;

void insert();
void insertAt();
void deletenode();
void deleteAt(int pos);
int countItems();
void display();

void main()
{clrscr();
int op;
char op2;
do{
cout<<"Enter Option\n1)Add Node at End of List\n2)Insert node at position\n3)Delete last node\n4)Delete node at a position\n5)Count number of items in the List\n6)Display List\n";
cin>>op;
switch(op)
{case 1:insert();
	break;
case 6: display();
	break;
case 2: insertAt();
	break;
case 3: deletenode();
	break;
case 4: {int pos;
	cout<<"\nEnter node position";
	cin>>pos;
	deleteAt(pos);}
	break;
case 5: {cout<<"\nThere are "<<countItems()<<" nodes present in the list.";}
	break;
};
cout<<"\nRun Again?";
cin>>op2;
}while(op2=='y');
getch();}

void insert()
{node *temp=new node;
int d;
cout<<"\nEnter data";
cin>>d;
if(head==NULL)
	{temp->data=d;
	head=temp;
	tail=temp;
}
else{
	temp->data=d;
	tail->next=temp;
	tail=temp;
	tail->next=head;}
}


void insertAt()
{node *temp=new node,*temp2=new node,*temp3= new node;
temp2=head;
int d,pos,count=1;
cout<<"Enter data and position of insertion" ;
cin>>d>>pos;
temp->data=d;
if(countItems()<(pos-1))
	cout<<"Linked List does not have that many elements";
else if(pos==1)
	{temp->next=head;
	head=temp;
	tail->next=head;}
else if(countItems()==pos-1)
	{tail->next=temp;
	tail=temp;
	tail->next=head;}
else{
	while(count!=pos-1)
		{temp2=temp2->next;
		++count;}
	temp3=temp2->next;
	temp2->next=temp;
	temp->next=temp3;}
}


void deletenode()
{node *temp=new node;
temp=head;
if(head==NULL)
	cout<<"\nNo nodes present.";
else
	{node *temp=new node;
	temp=head;
	while(temp->next!=tail)
		temp=temp->next;
	temp->next=head;
	tail=temp;
	tail->next=head;
}
}

void deleteAt(int pos)
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
	{cout<<"\nNo nodes present.";}
else if(pos>countItems())
	{cout<<"\nLinked List does not have that many nodes present."; }
else if(pos==1)
	{head=head->next;
	tail->next=head;}
else if(pos==countItems())
	{deletenode(); }
else{
	while(count!=pos-1)
		{temp=temp->next;
		++count;}
	node *temp2=new node;
	temp2=(temp->next)->next;
	temp->next=temp2;
    }
}
	
int countItems()
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
{cout<<"\nNo nodes present.";
return 0;}
else
{while(temp!=tail)
{temp=temp->next;
++count;}
return (count);
}
}


void display()
{if(head==NULL)
cout<<"\nNo Nodes present.";
else{
	node *temp=new node;
	temp=head;
	while(temp!=tail)
		{cout<<temp->data<<"->";
		temp=temp->next;
		}
	cout<<tail->data<<"->";
	cout<<"Head...";
	}
}
*/

