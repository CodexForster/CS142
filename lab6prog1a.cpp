#include<iostream>
using namespace std;

//function prototype for binary search
int binsearch(int arr[],int low,int up, int k);

int main()
{int arr[100],n,m;
cout<<"Enter number of elements in the array (max 100)";
cin>>n;
cout<<"\nEnter the elements of the sorted array:";
for(int i=0;i<n;i++)
cin>>arr[i];
cout<<"\nEnter the number you want to search for";
cin>>m;
int ans;
ans=binsearch(arr,0,(n-1),m);
	if(ans==(-1))
		cout<<"\nElement not found.";
	else
		cout<<"\nPosition of element is = "<<ans+1;
		
	return 0;
}

//function definition
int binsearch(int arr[],int low,int up, int k)
{
	int mid=(low+up)/2;
	if(k<=arr[up]&&k>=arr[low])
	{
		if(k==arr[mid])
			return mid;
		else if(k>mid)
			binsearch(arr,mid+1,up,k);
		else
			binsearch(arr,low,mid-1,k);
				}
	else
		return (-1);
}
