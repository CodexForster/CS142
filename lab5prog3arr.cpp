#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(int arr[], int one, int two) {
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


void bubblesort(int a[], int b)
{	int p,q,t;
	for(int i=0;i<b;i++)
	{
		p=0;
		q=1;
	for(int j=0;j<b-1;j++)
	{
		if(a[p]>a[q])                        
		{                                   
			t=a[p];                 
			a[p]=a[q];            
			a[q]=t;
		}
		p++;
		q++;
	}
	}
}


int main() {
	double t1b,t2b,t1q,t2q;
	int arr1[100],arr2[100],arr3[1000],arr4[1000],arr5[2500],arr6[2500],arr7[5000],arr8[5000],arr9[8000],arr10[8000],arr11[10000],arr12[10000];
	int c1=100,c2=1000,c3=2500,c4=5000,c5=8000,c6=10000;
	for(int i=0;i<c1;i++)
	{arr1[i]=rand()%100;			//this generates 100 numbers from 0 to 100
	arr2[i]=arr1[i];}
	for(int i=0;i<c2;i++)
	{arr3[i]=rand()%100;			//this generates 1000 numbers from 0 to 100
	arr4[i]=arr3[i];}
	for(int i=0;i<c3;i++)
	{arr5[i]=rand()%100;			//this generates 2500 numbers from 0 to 100
	arr6[i]=arr5[i];}
	for(int i=0;i<c4;i++)
	{arr7[i]=rand()%100;			//this generates 5000 numbers from 0 to 100
	arr8[i]=arr7[i];}
	for(int i=0;i<c5;i++)
	{arr9[i]=rand()%100;			//this generates 8000 numbers from 0 to 100
	arr10[i]=arr9[i];}
	for(int i=0;i<c6;i++)
	{arr11[i]=rand()%100;			//this generates 10000 numbers from 0 to 100
	arr12[i]=arr11[i];}
	
	
	cout<<"\nFor an array of size 100, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr1,c1);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr2,0,c1);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor an array of size 1000, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr3,c2);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr4,0,c2);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
        
    cout<<"\nFor an array of size 2500, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr5,c3);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr6,0,c3);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor an array of size 5000, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr7,c4);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr8,0,c4);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
		
	cout<<"\nFor an array of size 8000, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr9,c5);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr10,0,c5);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
	cout<<"\nFor an array of size 10000, these are the time taken for both sorts:";
        t1b = clock();
        bubblesort(arr11,c6);
        t2b = clock();
        cout << "\nBubble Sort\t: " << (t2b - t1b)/CLK_TCK << " sec\n";
		t1q = clock();
        quicksort(arr12,0,c6);
        t2q = clock();
        cout << "\nQuick Sort\t: " << (t2q - t1q)/CLK_TCK << " sec\n";
		
				
		return 0;



}

