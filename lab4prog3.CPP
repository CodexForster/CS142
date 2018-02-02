#include <iostream>

#include <string.h>

using namespace std;



struct node{

	char name[25];

	int number;

	char issue[140];

	node *prev;

	bool palindrome (char name[]);
};


 //function to check if name is palindrome

bool node::palindrome(char name[]){

	int len;

	len=strlen(name);

	char tempname[len]; //creates temporary string

	for (int i=0;i<len;i++){ 

		if (name[i] >= 'A' && name[i] <= 'Z')

		{

			tempname[i]=name[i]+32;

		}

		else if (name[i] >= 'a' && name[i] <= 'z')

		{

			tempname[i]=name[i];

		}

	}

	for(int i=0;i<strlen(tempname);++i){

		if(tempname[i]==tempname[len-1-i])

			return 1;

		else

			return 0;

	}

}



class queueLL{

	node *front;

	node *rear;

public:

	queueLL(){//default constructor

	front=rear=NULL;

	}

	//functions

	void queue();

	void display();

};



void queueLL::queue(){

	char a[3];

	node *temp=new node;

	cout<<"enter your name";

	gets(a); //clears the buffer

	gets(temp->name);

	cout<<"enter your number";

	cin>>(temp->number);

	cout<<"enter your issue";

	gets(a);

	gets(temp->issue);

	if(rear==NULL){ 

		front=temp;

		rear=temp;

	}else{

		if(temp->palindrome(temp->name)){

			temp->prev=front;

			front=temp;

		}else{

			rear->prev=temp;

			rear=temp;

		}

		

	}

}



void queueLL::display(){

	node *temp;

	temp=front;

	while(temp!=NULL){ 

		cout<<temp->name<<"\t";

		cout<<temp->number<<"\t";

		cout<<temp->issue<<"\t";

		temp=temp->prev;

	}

}

 int main(){

 	queueLL q;

 	int choice;

    int x;

    while(1)//makes a menu

    {

     

        cout<<"\n\t\tCUSTOMER SERVICE\n\n";

        cout<<"1:PLACE A COMPLAINT\n2:EXIT";

        cout<<"\nEnter your choice(1-2): ";

        cin>>choice;

        switch(choice)

        {

            case 1:

            	q.queue();

            	q.display();

                break;

            case 2:

                return 0;

                break;

            default:

                cout<<"\nPlease enter correct choice(1-2)!!";

                break;

        }

    }

  	return 0;

 }