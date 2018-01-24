/*Program Code for Assignment : Lab 3

Please note that this code was written in TurboC++ and i just changed the header files to 

make it run in g++(Linux)...(i dont't have Linux so i tested it on Ideone)

Worst Case if this code doesn't work : The main code is also in a multi-line comment at the end. */ 


#include<iostream>
#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//node definition with 2 pointers(doubly linked list) and on variable for data
class node{
public:
int data;
node * next;
node *prev;
node(){
data=0;
next=NULL;
prev=NULL; }
}*head,*tail;

//function prototypes:
void insert(int);
void insertAt(int,int);
void deletenode();
void deleteAt(int pos);
int countItems();
void display();
//I don't see the use of doubly linked list with the above functions,
//so i included this extra function:
void displayrev();

int main()
{
int op;
char op2;
do{
cout<<"\nEnter Option\n1)Add Node at End of List\n2)Insert node at position\n3)Delete last node\n4)Delete node at a position\n5)Count number of items in the List\n6)Display List\n7)Display list in reverse order";
cin>>op;
switch(op)
{case 1:{int dat;
	cout<<"Enter data";
	cin>>dat;
	insert(dat);}
	break;
case 2: {int dat,pos;
	cout<<"\nEnter positiion and data";
	cin>>pos>>dat;
	insertAt(pos,dat);}
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
case 6: display();
	break;
case 7: displayrev();
	break;
};
cout<<"\nRun Again?";
cin>>op2;
}while(op2=='y');
return 0;}

//function definitions start here:

//function to insert node at the end of the list
void insert(int dat)
{node *temp=new node;
temp->data=dat;
if(head==NULL)
	{head=temp;
	 head->prev=NULL;
	 tail=temp;
	 tail->next=NULL;
	}
else
	{tail->next=temp;
	 temp->prev=tail;
	 tail=temp;
	 tail->next=NULL;  //check later
	}
}



//function to insert node at any position
void insertAt(int pos, int dat)
{node *temp =new node;
int count=1;
if(countItems()<(pos-1))
	cout<<"\nLinked List does not have that many elements";
else if(countItems()==(pos-1))
	{int dat;
	cout<<"\nEnter data";
	cin>>dat;
	insert(dat);}
else if(pos==1)
	{temp->data=dat;
	temp->next=head;
	head->prev=temp;
	head=temp;}
else{
	node *temp2=new node;
	node *temp3=new node;
	temp3->data=dat;
	temp=head;
	while(count!=pos-1)
		{temp=temp->next;
		++count;}
	temp2=temp->next;
	temp->next=temp3;
	temp3->prev=temp;
	temp3->next=temp2;
	temp2->prev=temp3;
}
}


//function to delete the last node
void deletenode()
{node *temp=new node;
temp->next=tail->prev;
(temp->next)->next=NULL;
tail=temp->next;}


//function to delete node at any position
void deleteAt(int pos)
{
node *temp =new node;
int count=1;
if(countItems()<(pos-1))
	cout<<"\nLinked List does not have that many elements";
else if(countItems()==(pos-1))
	deletenode();
else if(pos==1)
	{if(head->next==NULL)
		{cout<<"\nLinked List length is one, so the first node cannot be deleted due to my limitations";
		}
	 else{head=head->next;}
	 }
else{
	node *temp2=new node;
	node *temp3=new node;
	temp=head;
	while(count!=pos-1)
		{temp=temp->next;
		++count;}
	temp3=temp->next;
	temp2=(temp->next)->next;
	temp->next=temp2;
	temp2->prev=temp;
	delete temp3;
}
}

//function to count the number od nodes present in the list
int countItems()
{node *temp=new node;
temp=head;
if(head==NULL)
	return 0;
else	{
	int count=0;
	while(temp!=NULL)
		{++count;
		temp=temp->next;}
	return count;
	}
}


//function to display the linked list
void display()
{ if(head==NULL)
	cout<<"There are no nodes in the Linked List";
else{
	node *temp=new node;
	temp=head;
	while(temp!=NULL)
		{cout<<temp->data<<" -> ";
		temp=temp->next;}
	cout<<"NULL";
	}
}


//extra function
//function to display the Linked List in reverse order
void displayrev()
{if(tail==NULL)
	cout<<"There are no nodes in the Linked List";
else{
	node *temp=new node;
	temp=tail;
	while(temp!=NULL)
		{cout<<temp->data<<" <-";
		temp=temp->prev;
		}
	cout<<"NULL" ;
	}
}




/*
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

//node definition with 2 pointers(doubly linked list) and on variable for data
class node{
public:
int data;
node * next;
node *prev;
node(){
data=0;
next=NULL;
prev=NULL; }
}*head,*tail;

//function prototypes:
void insert(int);
void insertAt(int,int);
void deletenode();
void deleteAt(int pos);
int countItems();
void display();
//I don't see the use of doubly linked list with the above functions,
//so i included this extra function:
void displayrev();

void main()
{clrscr();
int op;
char op2;
do{
cout<<"\nEnter Option\n1)Add Node at End of List\n2)Insert node at position\n3)Delete last node\n4)Delete node at a position\n5)Count number of items in the List\n6)Display List\n7)Display list in reverse order";
cin>>op;
switch(op)
{case 1:{int dat;
	cout<<"Enter data";
	cin>>dat;
	insert(dat);}
	break;
case 2: {int dat,pos;
	cout<<"\nEnter positiion and data";
	cin>>pos>>dat;
	insertAt(pos,dat);}
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
case 6: display();
	break;
case 7: displayrev();
	break;
};
cout<<"\nRun Again?";
cin>>op2;
}while(op2=='y');
getch();}

//function definitions start here:

//function to insert node at the end of the list
void insert(int dat)
{node *temp=new node;
temp->data=dat;
if(head==NULL)
	{head=temp;
	 head->prev=NULL;
	 tail=temp;
	 tail->next=NULL;
	}
else
	{tail->next=temp;
	 temp->prev=tail;
	 tail=temp;
	 tail->next=NULL;  //check later
	}
}



//function to insert node at any position
void insertAt(int pos, int dat)
{node *temp =new node;
int count=1;
if(countItems()<(pos-1))
	cout<<"\nLinked List does not have that many elements";
else if(countItems()==(pos-1))
	{int dat;
	cout<<"\nEnter data";
	cin>>dat;
	insert(dat);}
else if(pos==1)
	{temp->data=dat;
	temp->next=head;
	head->prev=temp;
	head=temp;}
else{
	node *temp2=new node;
	node *temp3=new node;
	temp3->data=dat;
	temp=head;
	while(count!=pos-1)
		{temp=temp->next;
		++count;}
	temp2=temp->next;
	temp->next=temp3;
	temp3->prev=temp;
	temp3->next=temp2;
	temp2->prev=temp3;
}
}


//function to delete the last node
void deletenode()
{node *temp=new node;
temp->next=tail->prev;
(temp->next)->next=NULL;
tail=temp->next;}


//function to delete node at any position
void deleteAt(int pos)
{
node *temp =new node;
int count=1;
if(countItems()<(pos-1))
	cout<<"\nLinked List does not have that many elements";
else if(countItems()==(pos-1))
	deletenode();
else if(pos==1)
	{if(head->next==NULL)
		{cout<<"\nLinked List length is one, so the first node cannot be deleted due to my limitations";
		}
	 else{head=head->next;}
	 }
else{
	node *temp2=new node;
	node *temp3=new node;
	temp=head;
	while(count!=pos-1)
		{temp=temp->next;
		++count;}
	temp3=temp->next;
	temp2=(temp->next)->next;
	temp->next=temp2;
	temp2->prev=temp;
	delete temp3;
}
}

//function to count the number od nodes present in the list
int countItems()
{node *temp=new node;
temp=head;
if(head==NULL)
	return 0;
else	{
	int count=0;
	while(temp!=NULL)
		{++count;
		temp=temp->next;}
	return count;
	}
}


//function to display the linked list
void display()
{ if(head==NULL)
	cout<<"There are no nodes in the Linked List";
else{
	node *temp=new node;


	temp=head;
	while(temp!=NULL)
		{cout<<temp->data<<" -> ";
		temp=temp->next;}
	cout<<"NULL";
	}
}


//extra function
//function to display the Linked List in reverse order
void displayrev()
{if(tail==NULL)
	cout<<"There are no nodes in the Linked List";
else{
	node *temp=new node;
	temp=tail;
	while(temp!=NULL)
		{cout<<temp->data<<" <-";
		temp=temp->prev;
		}
	cout<<"NULL" ;
	}
}

*/