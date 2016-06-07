/*	Title:  CST 370 Lab 6
	Author: Julia Diliberto
	ID:  002300804
	Date:  February 15, 2016
	File:  Lab6.cpp
	Desc:  This program will search for a user entered value in an array, using three
		   different binary search implementations.  For each implementation, one value
		   will be found and one not found.
	Usage: Binary search requires that the array to be searched be ordered.
*/

#include <iostream>
using namespace std;

void displayArray(int A[], int n)
{
	for (int i=0; i<n; i++)
		cout << A[i]<<" ";
	cout <<endl;

}

bool LinearSearch (int A[], int n, int x)
{
	for (int i=0; i<n; i++){
		if (x==A[i]){	
			return true;
		}
	}
	return false;
}

bool IterBinarySearch (int A[], int n, int x)
{
	int low=0;
	int high=n-1;
	while (low<=high)
	{
		int mid=low +(high-low)/2;
		if (x==A[mid]) 
			return true;
		else if (x<A[mid])
			high=mid-1;
		else 
			low=mid+1;
	}
	return false;

}

bool RecursiveBinarySearch (int A[], int low, int high, int x)
{

	if (low>high){
		return false;
	}
	else {
		int mid=low + (high-low)/2;
		if (x==A[mid])
			return true;
		else  if (x<A[mid])
			 return RecursiveBinarySearch (A, low, mid-1, x); 
		else
			return RecursiveBinarySearch (A, mid+1, high, x);
	}
}

int main()
{
	int myArray[]={2,4,7,9,13,26,78,83,101};
	int value;
	bool result;


//Display Array
	cout<<"This is the array: ";
	displayArray(myArray,9);

//Linear Search
	cout <<"Please enter an integer value: ";
	cin >> value;
	result = LinearSearch(myArray, 9, value);
	cout <<"Linear Search says..."<<endl;
	if (result)
		cout<<value<<" is in the array"<<endl;
	else
		cout<<value<<" is not in the array"<<endl;


//Iterative Binary Search
	cout <<"Please enter an integer value: ";
	cin >> value;
	result = IterBinarySearch(myArray, 9, value);
	cout <<"Iterative Binary Search says..."<<endl;
	if (result)
		cout<<value<<" is in the array"<<endl;
	else
		cout<<value<<" is not in the array"<<endl;

//Recursive Binary Search
	cout <<"Please enter an integer value: ";
	cin >> value;
	result = RecursiveBinarySearch(myArray, 0, 8, value);
	cout <<"Recursive Binary Search says..."<<endl;
	if (result)
		cout<<value<<" is in the array"<<endl;
	else
		cout<<value<<" is not in the array"<<endl;

}