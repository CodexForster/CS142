#include<iostream>
using namespace std;


struct node
{
	int data;//stores data of the node
	node *next;//stores address of the next element in the list
};

//class definition for carrying out operations on the list
class list
{
	private:
	node *head, *tail;
	
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
		temp->next=NULL;
		if(tail==NULL)
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
	
	int val(int n)
	{node *temp =new node;
	temp=head;
	for(int i=1;i<n;i++)
	temp=temp->next;
	int data=temp->data;
	//delete temp;
	return data;
	}
	

};



int binsearch(list a, int up, int low, int k);

int main()
{
	list a;
	int n,dat1;
	cout<<"Enter number of nodes you want in the list";
	cin>>n;
	node *temp=new node;
	for(int i=0;i<n;i++)
	{cout<<"\nEnter data for node "<<i+1;
	cin>>dat1;
	a.insert(dat1);
	}
	int m;
	cout<<"\nEnter the element you want to search for";
	cin>>m;
	int ans;
	ans=binsearch(a,1,n,m);
	if(ans==-1)
	cout<<"\nElement not found";
	else
	cout<<"\nThe element location is "<<ans;
	}
	

//function definition
int binsearch(list a, int low, int up, int k)
{
	int mid = (up+low)/2;
	if(k<=a.val(up)&&k>=a.val(low))
	{	
		if(k==a.val(mid))
			return mid;
		else if(k>a.val(mid))
			binsearch(a,mid+1,up,k);
		else
			binsearch(a,low,mid-1,k);
			}
	else
		return (-1);
}



