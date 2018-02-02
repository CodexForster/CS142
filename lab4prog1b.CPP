#include<iostream>
#include<curses.h>

using namespace std;



struct node{ 
	int data;

	node *prev;

};



class queueLL{

	node *front; //creates two node type pointers

	node *rear;

public:

	queueLL(){//default constructor

	front=rear=NULL;

	}

	//functions

	void queue(int data);

	void leave();

	void display();

};

void queueLL::queue(int data){//adds new node at rear of the queue

	node*temp=new node;

	temp->data= data;

	temp->prev=NULL;

	if(rear==NULL){ //checks if there are any elements in the queue

		front=temp;

		rear=temp;

	}else{

		rear->prev=temp; //links the last node to the new node

		rear=temp; //points rear at temp

	}

}



void queueLL::leave(){ //removes a node from the front of the queue

	node *temp;

	temp=front; //points temp to first node in queue

	front=front->prev;//points front to second node in queue

	delete temp; //deletes first node

}



void queueLL::display(){

	node *temp;

	temp=front;

	while(temp!=NULL){ //traverses the queue from front to the rear

		cout<<temp->data<<"\t";

		temp=temp->prev;

	}

}

int main(){

 queueLL q;

    int choice;

    int x;

    while(1)//makes a menu

    {


	cout<<"1:Add element\n2:Delete element\n3:Display queue\n4:Exit";

	cout<<"\nEnter your choice: ";

	cin>>choice;

	switch(choice)

	{

	    case 1:

		cout << "Enter the number to add:";

		cin >> x;

		q.queue(x);

		break;

	    case 2:

		q.leave();

		break;

	    case 3:

		q.display();

		break;

	    case 4:

		return 0;

		break;

	    default:

		cout<<"\nPlease enter correct choice(1-4)!!";

		break;

	}



    }

    return 0;

}
