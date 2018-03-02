//----------->> QUICKSORT IN AN LINKED LIST <<--------------
#include <iostream>
using namespace std;

//Creating the structure for node
struct node
{
	int data;//stores data of the node
	node *next;//stores address of the next element in the list
};

//class definition for carrying out operations on the list
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
	
	// The move function is a replacement for the expression a[i] in case of arrays
	// It just moves to our desired location
	node *move(int c)
	{
		node *tmp=new node;
		tmp=head;
		for(int i=1;i<c;i++)
		tmp=tmp->next;
		return tmp;
	}
	
    void quicksort(int left, int right)
   {
   	int i = left, j = right;//The left end and right end of the elements
            node *tmp=new node;
            node *pivot=new node;
            
            pivot=move((left+right)/2);//pivot point set as middle node
            while (i <= j) 
            {
                   while (move(i)->data < pivot->data)
                   i++;                   // skipping the elemnts from left till move(i)->data < pivot->data
                   while (move(j)->data > pivot->data)
                   j--;                   // skipping the elemnts from right till move(j)->data > pivot->data
                   if (i <= j)            //if athe conditions fail then they are swapped
                   {
                           tmp->data = move(i)->data;
                           move(i)->data = move(j)->data;
                           move(j)->data = tmp->data;
                           i++;
                           j--;
                    }
       };
       if (left < j)                 // Doing this recursively  for the partitions made by the middle elemnts
            quicksort(left, j); 
      if (i < right)
            quicksort( i, right);
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
	a.quicksort(1,c);
	cout<<"\n The sorted list is:";
	a.display();
	return 0;
}
