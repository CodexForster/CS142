#include <iostream>
using namespace std;


void bubblesort(int a[], int b)
{	int p,q,t;
	for(int i=0;i<b;i++)
	{
		p=0;
		q=1;
	for(int j=0;j<b-1;j++)
	{
		if(a[p]>a[q])                         //Comparing the adjacent two elemnts of the array
		{                                    //and swapping them in ascending order
			t=a[p];                 //and this is iterated for every element
			a[p]=a[q];             //And this way the array is processed n(no of elements) times
			a[q]=t;
		}
		p++;
		q++;
	}
	}
}


int main() {
	int arr[100],c=0;
	cout<<"\n Enter the number of elements in the array and then the elements themselves";
	cin>>c;
	for(int i=0;i<c;i++)
	{
		cin>>arr[i];
	}
	cout<<"\n The original array :\n";
	for(int k=0;k<c;k++)
	{
		cout<<arr[k]<<"-->";
	}
	cout<<"END\n";
	bubblesort(arr,c);
	cout<<"\n The sorted array :\n";
	for(int k=0;k<c;k++)
	{
		cout<<arr[k]<<"-->";
	}
	cout<<"END\n";
	return 0;

}
