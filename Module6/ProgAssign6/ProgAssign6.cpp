/*	Title:  CST 370 Programming Assignment 6
	Author: Julia Diliberto
	ID:  002300804
	Date:  February 13, 2016
	File:  ProgAssign6.cpp
	Desc:  This program sorts a given array of integers using 3 applications of a partial
		   insertion sort.  
	Usage: steps1 and steps2 contain the gap between elements in each subarray that will be sorted in 
		   the applications.
*/

#include <iostream>
using namespace std;

void partial_insertion_sort (int myArray[], int length, int k){
//separates myArray into k subarrays and sorts them by insertion sort
	 	
	int hole; //index of array element to be filled
	int value; //value of array element to be inserted

	for (int b=0; b<k;b++)
		for (int i = b+k; i <length; i+=k){
			value=myArray[i];
			hole=i;
			while (hole-k>=0 && myArray[hole-k]>value){ /*loop terminates when array start has been reached
													   or when value >= the value at the next smaller index*/
				myArray[hole]=myArray[hole-k];
				hole=hole-k;
			}
			myArray[hole]=value;
		}
}

int main()
{
	int length=10;
	int array1[]={2, 5, 6, 4, 10, 9, 8, 1, 10, 5};
	int array2[]={2, 5, 9, 4, 10, 7, 8, 1, 11, 5};
	int steps1[3]={5,3,1};
	int steps2[3]={5,2,1};

	int step=1;
	for (int j:steps1){
		partial_insertion_sort(array1,length, j);
		cout<<"array1, step "<<step<<": ";
		for (int i=0;i<length;i++)
			cout <<array1[i]<<" ";
		cout <<endl;
		step++;
	}
		
	step=1;
	for (int j:steps2){
		partial_insertion_sort(array2,length, j);
		cout<<"array2, step "<<step<<": ";
		for (int i=0;i<length;i++)
			cout <<array2[i]<<" ";
		cout <<endl;
		step++;
	}	
	return 0;
}
	