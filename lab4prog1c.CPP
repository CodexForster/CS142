#include <iostream>

using namespace std;



int Stack[20]; //creates an array of size 20

int top=-1;


//function to check if stack is empty
bool isEmpty(){ 

	if(top==-1)

		return 1;

	else

		return 0;

}


//function to check if stack is full
bool isFull(){ 

	if(top==19)

		return 1;

	else

		return 0;

}


//function to push an element
void push(int data){

	if(isFull()){

		cout<<"Stack is full";

	}else{

		++top;

		Stack[top]=data;

	}

}


//function to display all elements
void display(){ 

int i;

	if(isEmpty()){

		cout<<"Stack is empty";

	}else{

		for(i=0;i<=top;i++){

			cout<<Stack[i]<<"\n";

		}

	}

}


//function to pop element
void pop(){

	if(isEmpty()){

		cout<<"Stack is empty";

	}else

		--top;

}



int main(){

    int choice;

    int x;

//makes a menu

    while(1)

    {

        cout<<"1:Push\n2:Pop\n3:Display stack\n4:Exit";

        cout<<"\nEnter your choice(1-4): ";

        cin>>choice;

        switch(choice)

        {

            case 1:

            	cout << "Enter the number to push:";

            	cin >> x;

                push(x);

                break;

            case 2:

                pop();

                break;

            case 3:

                display();

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