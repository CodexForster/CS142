#include <iostream>
using namespace std;

int heap[100];
int len=0;
void insert(int key)
{
	heap[len]=key;
	
	int i=len;
	int p=(i-1)/2;
	len++;
	while(heap[i]>=heap[p] && i!=0)
	{
		int temp=0;
		temp=heap[i];
		heap[i]=heap[p];
		heap[p]=temp;                                     
		i=p;
		p=(i-1)/2;
	}
	
}

void display()
{
	for(int i=0;i<len;i++)
	{
		cout<<heap[i]<<"\t";
	}
}

void remove_h()
{
	heap[0]=heap[len-1];
	len--;
	int i=0;
	int c1=2*i+1;
	int c2=2*i+2;
	while(c1<len && c2<len )
	{
		
	if(heap[c1]==0 && heap[c2]==0)
	{
		break;
		
	
	}
	
		else if(heap[c1]!=0 && heap[c2]!=0)
	{
		cout<<"\n block1\n";
		if(heap[c1]>heap[c2])
		{
			
				int temp=0;
				temp=heap[i];
				heap[i]=heap[c1];
				heap[c1]=temp;  	
				i=c1;
		c1=2*i+1;
		c2=2*i+2;
		}
		else
		{
				int temp=0;
				temp=heap[i];
				heap[i]=heap[c2];
				heap[c2]=temp;                                  
				i=c2;
		c1=2*i+1;
		c2=2*i+2;
		}
		
	}
	else if(heap[c1]==0 || heap[c2]==0)
	{
		cout<<"\n block2\n";
		if(heap[c1]!=0)
		{
			if(heap[c1]>heap[i])
			{
				int temp=0;
				temp=heap[i];
				heap[i]=heap[c1];
				heap[c1]=temp;                                    
			}
			i=c1;
			c1=2*i+1;
			c2=2*i+2;
		}
		if(heap[c2]!=0)
		{
			if(heap[c2]>heap[i])
			{
				int temp=0;
				temp=heap[c2];
				heap[i]=heap[c2];
				heap[c2]=temp;                            	
			}
			i=c2;
			c1=2*i+1;
			c2=2*i+2;
			
		}
		
	}
		
	
	}
}

int main() {
	int v=0,n=0;
	cout<<"\n Enter the initial no elememts of MAX HEAP";
	cin>>n;
	cout<<"\n Enter the elements";
	for(int i=0;i<n;i++)
	{
		cin>>v;
		insert(v);
	}
	char op;
	int op2;
	do{
		cout<<"\nEnter operation\n1)Insert\n2)Remove\n3)Display\n";
		cin>>op2;
		switch(op2)
		{
			case 1: {int a;
					cout<<"\nEnter element: ";
					cin>>a;
					insert(a);
					break;}
			case 2: {remove_h();				
					break;}
			case 3: {display();
					break;}
		}
	}while(op!='n');
	
	cout<<"\n\n";
	return 0;
}
