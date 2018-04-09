#include<iostream>
using namespace std;

int n=0;
//class definition
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
int search(int a);
void deletenode();
int display(node * temp);
int count(node * temp);
int range(node * temp, int one, int two);


int main()
{
	int op1,e;
	char op2;
	do{
		cout<<"\nEnter option\n1)Insert\n2)Search\n3)Delete\n4)Dislay\n5)Count\n6)Range";
		cin>>op1;
		switch(op1)
		{
			case 1: insert();
				break;
			case 2: {int a;
				cout<<"\nEnter the element you want to search";
				cin>>a;
				int b=search(a);
				break;}
			case 3: deletenode();
				break;
			case 4: e=display(head);
				break;
			case 5: {n=0;
					int d=count(head);
					cout<<"\nThe number of nodes in the BST is "<<n;
				break;}
			case 6:{
				int one,two;
				cout<<"\nEnter the two bounds";
				cin>>one>>two;
				int f=range(head,one,two);
				break;
			}
		}
	cout<<"\nRun again?";
	cin>>op2;
	}while(op2=='y');
	
	return 0;
	
}

//function definitions


void insert(){
		int data;
		cout<<"\nEnter data";
		cin>>data;
		node* temp = new node;
		temp->data= data;
		temp->parent=temp->left=temp->right=NULL;
		
		if(head==NULL){
			head=temp;
		}
		else{
		node* cur= new node;
		cur=head;
			while(true){
				if((cur->data)>(temp->data)){
					if(cur->left==NULL){
						cur->left=temp;
						temp->parent=cur;
						break;
					}
					else{
						cur=cur->left;
					}
				}
				else{
					if(cur->right==NULL){
						cur->right=temp;
						temp->parent=cur;
						break;
					}
					else{
						cur=cur->right;
					}
				}
			}
		}
	}



int display(node * temp)
{
	if(temp==NULL)
	{return 0;}
	display(temp->left);
		cout<<temp->data;
	display(temp->right);
	
}
	

int search(int a)
{
int b=1;
node *temp=new node;
temp=head;
while(1)
{
	if(temp->data>a)
	{
		if(temp->left!=NULL)
			temp=temp->left;
		else
			break;
	}
	else if(temp->data<a)
	{
		if(temp->right!=NULL)
			temp=temp->right;
		else
			break;
	}
	else if(temp->data==a)
		{b=0;
		break;}
}
if(b==0)
{cout<<"\nThe node with data "<<a<<" is present";
return 1;
}
else if(b==1)
{
cout<<"\nThe node with data "<<a<<" is not present";
return 0;
}}


void deletenode()
{int a;
cout<<"\nEnter the number you want to delete";
cin>>a;
if(search(a)==1)
{cout<<"\ndeleting...";

	node *temp=new node;
	node * temp2=new node;
	temp=head;
	// Head
	while(temp->data!=a)
	{
		if(temp->data>a)
		temp=temp->left;	
		else
		temp=temp->right;
	}

	
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		if(temp->right!=NULL)
			{temp2=temp;
			temp=temp->right;
			if(temp->left==NULL&&temp->right==NULL)
			{
			int dat=temp->data;
			temp=temp->parent;
			temp->right=NULL;
			temp2->data=dat;
			}
			else{
			while(temp->left!=NULL)
				temp=temp->left;
			int dat=temp->data;
			temp=temp->parent;
			temp->left=NULL;
			temp2->data=dat;	
			}}
		 else
		 	{temp=temp->left;
		 	if(temp->right==NULL&&temp->left==NULL)
			{
			int dat=temp->data;
			temp=temp->parent;
			temp->left=NULL;
			temp2->data=dat;
			}
			 
			else{
			 while(temp->right!=NULL)
				temp=temp->right;
				
			int dat=temp->data;
			temp=temp->parent;
			temp->right=NULL;
			head->data=dat;	
			}}
	}
	
	else
	{	if((temp->parent)->data>a)      //this is to delete if the node you want to delete is a leaf
			{
			temp=temp->parent;
			temp->left=NULL;
			}
		else
			{
				temp=temp->parent;
				temp->right=NULL;
			}
			
 	} 
}
}

int count(node *temp)
{
	if(temp==NULL)
	return 0;
	count(temp->left);
		++n;
	count(temp->right);
	
}

int range(node *temp, int one, int two)
{
if(temp==NULL)
	{
		return 0;
	}
	range(temp->left,one,two);
	if(temp->data<=two && temp->data>=one)
	{
		cout<<temp->data<<"-";
	}
	
	range(temp->right,one,two);
}
