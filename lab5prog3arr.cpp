#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


void quicksort(int a[], int left, int right)
   {
   	int i = left, j = right-1;//The left end and right end of the elements
            int tmp;
            int pivot = a[(left + right) / 2];//pivot point set as middle element
            while (i <= j)
            {
                   while (a[i] < pivot)
                   i++;                   // skipping the elemnts from left till a[i]<pivot
                   while (a[j] > pivot)
                   j--;                   // skipping the elemnts from right till a[j]>pivot
                   if (i <= j)            //if athe conditions fail then they are swapped
                   {
                           tmp = a[i];
                           a[i] = a[j];
                           a[j] = tmp;
                           i++;
                           j--;
                    }
       };
       if (left < j)                 // Doing this recursively  for the partitions made by the middle elemnts
            quicksort(a, left, j); 
      if (i < right)
            quicksort(a, i, right);
}


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
	double t1b,t2b,t1q,t2q;
	int arr1[100],arr2[1000],arr3[2500],arr4[5000],arr5[8000],arr6[10000];
	int c1=100,c2=1000,c3=2500,c4=5000,c5=8000,c6=10000;
	for(int i=0;i<c1;i++)
	arr1[i]=rand()%100;			//this generates 100 numbers from 0 to 100

	for(int i=0;i<c2;i++)
	arr2[i]=rand()%100;			//this generates 1000 numbers from 0 to 100
	
	for(int i=0;i<c3;i++)
	arr3[i]=rand()%100;			//this generates 2500 numbers from 0 to 100

	for(int i=0;i<c4;i++)
	arr4[i]=rand()%100;			//this generates 5000 numbers from 0 to 100
	
	for(int i=0;i<c5;i++)
	arr5[i]=rand()%100;			//this generates 8000 numbers from 0 to 100

	for(int i=0;i<c6;i++)
	arr6[i]=rand()%100;			//this generates 10000 numbers from 0 to 100
	
	cout<<"\nFor an array of size 100, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr1,c1);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr1,0,c1);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		cout<<"\nFor an array of size 1000, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr2,c2);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr2,0,c2);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
        
        cout<<"\nFor an array of size 2500, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr3,c3);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr3,0,c3);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		cout<<"\nFor an array of size 5000, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr4,c4);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr4,0,c4);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		
	cout<<"\nFor an array of size 8000, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr5,c5);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr5,0,c5);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor an array of size 10000, these are the time tiken for both sorts:";
        t1b = clock();
        bubblesort(arr6,c6);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr6,0,c6);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		
		
		
		
		return 0;



}
