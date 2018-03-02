#include <iostream>
using namespace std;


//function prototype for quicksort
void quicksort(int arr[], int one, int two);


//main starts here
int main() {
	int arr[100],c=0;
	cout<<"\n Enter the number of elements in the array";
	cin>>c;
	for(int i=0;i<c;i++)
	{
		cin>>arr[i];
	}
	cout<<"\n The original array :\n";
	for(int k=0;k<c;k++)
	cout<<arr[k]<<"-";
	
	quicksort(arr,0,c-1);

	cout<<"\n The sorted array :\n";
	for(int k=0;k<c;k++)
	cout<<arr[k]<<"-";
	
	return 0;
}


//function definition of quicksort   -           things we add as comments for such short programs as comments carries "25%" marks
void quicksort(int arr[], int one, int two)
 {
      int i = one, j = two;
      int tmp;
      int pivot = arr[(one + two) / 2];

      while (i <= j) {
            while (arr[i] < pivot) 
                  i++;
            while (arr[j] > pivot) 
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (one < j) 
            quicksort(arr, one, j);

      if (i < two) 
            quicksort(arr, i, two);
}




