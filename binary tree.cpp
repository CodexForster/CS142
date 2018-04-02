#include<iostream>
using namespace std;

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
			case 2: {int a;
				cout<<"\nEnter the element you want to search";
				cin>>a;
				int b=search(a);
				break;}
			case 3: deletenode();
				break;
			case 4: int a=display(head);
				break;
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
{
	node *temp=new node;
	node * temp2=new node;
	temp=head;
	// Head
	if(head->data!=a)
	// Rest 
	{while((temp->left)->data!=a||(temp->right)->data!=a)
	{
		if(temp->data>a)
		temp=temp->left;
		else if(temp->data<a)
		temp=temp->right;
	}}
	cout<<temp->data;
	if(((temp->left)->data==a)&&((temp->left)->left==NULL)&&((temp->left)->right==NULL))      //this is to delete if the node you want to delete is a leaf
		temp->left=NULL;
	else if(((temp->right)->data==a)&&((temp->right)->left==NULL)&&((temp->right)->right==NULL))
 		temp->right=NULL;
 	else if(((temp->left)->data==a)&&((temp->left)->left!=NULL))								//this is to delete if the node you want to delete is not a leaf
 		{temp2=temp;
 		while(temp2->left!=NULL)
 			temp2=temp2->left;
 		int one=temp2->data;
		temp2=temp2->parent;
 		temp2->left=NULL;
		temp->data=one;
		}
 	else if(((temp->left)->data==a)&&((temp->left)->right!=NULL))
	 	{temp2=temp;
 		while(temp2->left!=NULL)
	 		temp2=temp2->left;
 		int one=temp2->data;
		temp2=temp2->parent;
 		temp2->left=NULL;
		temp->data=one;
		}

 } 
}
