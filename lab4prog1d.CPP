#include <iostream>


using namespace std;



int queue[20];//creates an array

int front=0;
int rear=0;


//function to add element at rear
void enqueue(int data){ 

	if (rear == 20)

	cout << "\nQueue Reached Max!!";

    else

    	queue[rear++] = data;

}


//function to delete elements from front of queue
void dequeue(){	

	if (front == rear)

    	cout << "\n## Queue is Empty!";

    else

    	front++;

}


//function to display elements from front till rear
void display(){

	int i=0;

	for(i=front;i<rear;++i){

		cout<<queue[i];

	}

}



int main(){

    int choice;

    int x;

    //makes menu

    while(1)

    {

        cout<<"1:Push\n2:Pop\n3:Display queue\n4:Exit";

        cout<<"\nEnter your choice(1-4): ";

        cin>>choice;

        switch(choice)

        {

            case 1:

            	cout << "Enter the number to push:";

            	cin >> x;

                enqueue(x);

                break;

            case 2:

                dequeue();

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