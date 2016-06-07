/*	Title:  CST 370 Programming Assignment 5
	Author: Julia Diliberto
	ID:  002300804
	Date:  February 4, 2016
	File:  ProgAssign5.cpp

	Desc:  This program is implements Selection Sort on an array.  In Part A, the whole array is sorted. 
		   In Part B, the user determines how many elements should be sorted. In Part C, the array is partially sorted
		   and the result used to determine the median of the array values.
	Usage: myArray[0] holds the number of values in the array.
*/
#include <iostream>
using namespace std;

void SelectionSort(int myArray[])
{
	int i,j;
	int smallPos, smallest, numItems;
	
	numItems=myArray[0]+1;
	for (i=1; i<=numItems-1; i++)
	{
		smallPos=i;
		smallest=myArray[smallPos];
		for (j=i+1;j<=numItems-1;j++)
		{
			if (myArray[j]<smallest)
			{
				smallPos=j;
				smallest=myArray[smallPos];
			}
			if (smallest!=myArray[i])
			{
				myArray[smallPos]=myArray[i];
				myArray[i]=smallest;
			}
		}
	}
}

void SelectionSort(int myArray[], int k)
{
	int i,j;
	int smallPos, smallest, numItems;
	
	numItems=myArray[0]+1;
	for (i=1; i<=k; i++)
	{
		smallPos=i;
		smallest=myArray[smallPos];
		for (j=i+1;j<=numItems-1;j++)
		{
			if (myArray[j]<smallest)
			{
				smallPos=j;
				smallest=myArray[smallPos];
			}
			if (smallest!=myArray[i])
			{
				myArray[smallPos]=myArray[i];
				myArray[i]=smallest;
			}
		}
	}
}

int * getValues()
{
	int * a;
	int numItems=0;

	cout <<"How many integers would you like to enter? ";
	cin >> numItems;
	a = new int [numItems+1];
	a[0]=numItems;

	for (int i=1;i<=numItems;i++)
	{
		cout << "Enter an integer ";
		cin>>a[i];
	}
	return a;
}

void displayArray(int myArray[])
{
	int numItems;
	numItems=myArray[0];
	for (int i=1;i<numItems+1;i++)
	{
		cout << myArray[i]<<" ";
	}
	cout <<endl; 
}

void displayArray(int myArray[], int k)
{
	int numItems;
	numItems=myArray[0];
	for (int i=1;i<=k;i++)
	{
		cout << myArray[i]<<" ";
	}
	cout <<endl; 
}

int main ()
{
	int *a;
	int numItems;

//Part 1
	cout<<"Part 1"<<endl;
	a=getValues();
	numItems=a[0];
	cout <<"You entered: ";
	displayArray(a);
	SelectionSort(a);
	cout <<"Sorted values: ";
	displayArray(a);
	cout <<endl<<endl;

//Part 2
	cout<<"Part 2"<<endl;
	int k=-1;
	a=getValues();
	numItems=a[0];
	while (!(k>0) || !(k<=numItems))
	{
		cout <<"How many of those values do you want to sort (1-"<<numItems<<")? ";
		cin >>k;
	}
	SelectionSort(a,k);
	displayArray(a,k);
	cout <<endl;
	
//Part 3
	cout<<"Part 3"<<endl;
	float median;
	a=getValues();
	numItems=a[0];
	if (numItems%2==0)
		k=numItems/2+1;
	else
		k=(numItems+1)/2;
	SelectionSort(a,k);	
	if (numItems%2==0)
		median=(float(a[k-1])+float(a[k]))/2;
	else
		median=a[k];
	cout<<"The median of those numbers is: "<<median<<endl;
	return 1;


}