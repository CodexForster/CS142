#include <iostream>


using namespace std;



struct node{//creates node type structure

	int data;

	node *next;

};

class StackLL{

	public:

		node *top;

		StackLL(){

			top=NULL;

		}

	//functions

		void push(int data);

		void pop();

		void display();

		int isEmpty();

};

int StackLL::isEmpty(){

	if(top==NULL)

		return 1;

	else

		return 0;

}

//function to add new node to top of stack
void StackLL::push(int data){

	node *temp = new node;

	temp->data = data;

	temp->next = NULL;

	if(top!=NULL){

		temp->next = top;

	}

	top = temp;

}

//function to remove data from top of stack
void StackLL::pop(){

	node *temp;

	temp=top;

	if(temp==NULL){

	cout<<"Can't pop from empty stack";

	}else{

		top=top->next;

		delete temp;

	}

}
//function to display all elements of the stack
void StackLL::display(){

	node*temp;

	temp=top;

	while(temp!=NULL){

	cout<<temp->data<<endl;

	temp=temp->next;

	}

}

class QueueS{

	public:

		StackLL S1, S2;

	//functions

		void enqueue(int data);

		void dequeue();

		void display();

};


//function to add element to the queue
void QueueS::enqueue(int data){

	S1.push(data);

}


//function to remove data from queue
void QueueS::dequeue(){

	if(S1.isEmpty()){

		cout<<"Queue is empty";

	}else{

		while((S1.top)!= NULL){ //moves data from stack 1 to stack 2 so that last elememt becomes first element

			S2.push((S1.top)->data);

			(S1.top)=(S1.top)->next;

		}

		S2.pop();

		while((S2.top) != NULL){

			S1.push((S2.top)->data);

		}

	}

}


//function to display all the elements of the queue
void QueueS::display(){

	if(S1.isEmpty()){

		cout<<"Queue is empty";

	}else{

		while((S1.top)!= NULL){//moves data from stack 1 to stack 2 so that last elememt becomes first element

			S2.push((S1.top)->data);

			(S1.top)=(S1.top)->next;

		}

		S2.display();//displays elements of the stack 2

		while((S2.top) != NULL){//moves data from stack 2 to stack 1 so that last element becomes first element

			S1.push((S2.top)->data);

		}

	}

}



int main(){

	QueueS q;

    int choice;

    int x;


    while(1)

    {


	cout<<"1:Enqueue\n2:Dequeue\n3:Display Queue\n4:Exit";

	cout<<"\nEnter your choice(1-4): ";

	cin>>choice;

	switch(choice)

	{

	    case 1:

		cout << "Enter the number to push:";

		cin >> x;

		q.enqueue(x);

		break;

	    case 2:

		q.dequeue();

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