#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
	list a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;
	double t1b,t2b,t1q,t2q;
	int integer;
	int c1=100,c2=1000,c3=2500,c4=5000,c5=8000,c6=10000;
	for(int i=0;i<c1;i++)
	{integer = rand()%100;			//this generates 100 numbers from 0 to 100
	a1.insert(integer);			
	a2.insert(integer);}
	for(int i=0;i<c2;i++)
	{integer=rand()%100;			//this generates 1000 numbers from 0 to 100
	a3.insert(integer);
	a4.insert(integer);}
	for(int i=0;i<c3;i++)
	{integer=rand()%100;			//this generates 2500 numbers from 0 to 100
	a5.insert(integer);
	a6.insert(integer);}
	for(int i=0;i<c4;i++)
	{integer=rand()%100;			//this generates 5000 numbers from 0 to 100
	a7.insert(integer);
	a8.insert(integer);}
	for(int i=0;i<c5;i++)
	{integer=rand()%100;			//this generates 8000 numbers from 0 to 100
	a9.insert(integer);
	a10.insert(integer);}
	for(int i=0;i<c6;i++)
	{integer=rand()%100;			//this generates 10000 numbers from 0 to 100
	a11.insert(integer);
	a12.insert(integer);}
	
	//calculating time :
	cout<<"\nFor a linked list of size 100, these are the time taken for both sorts:";
        t1b = clock();
        a1.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a2.quicksort(1,c1);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor a linked list of size 1000, these are the time taken for both sorts:";
        t1b = clock();
        a3.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a4.quicksort(1,c2);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
        
    cout<<"\nFor a linked list of size 2500, these are the time taken for both sorts:";
        t1b = clock();
        a5.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a6.quicksort(1,c3);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor a linked list of size 5000, these are the time taken for both sorts:";
        t1b = clock();
        a7.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a8.quicksort(1,c4);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		
	cout<<"\nFor a linked list of size 8000, these are the time taken for both sorts:";
        t1b = clock();
        a9.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a10.quicksort(1,c5);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor a linked list of size 10000, these are the time taken for both sorts:";
        t1b = clock();
        a11.bubblesort();
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        a12.quicksort(1,c6);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		
		return 0;

}
