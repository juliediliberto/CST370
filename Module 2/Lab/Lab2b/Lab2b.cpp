/*	Title:  CST 370 Lab 2
	Author: Julia Diliberto
	ID:  002300804
	Date:  January 17, 2016
	File:  Lab2b.cpp
	Desc:  This program will take a decimal number as input from the user.
	       It will display that number, calculate the binary equivalent,
		   then display that number.
	Usage:  Other files required are Stack.cpp and Stack.h*/

#include <iostream>
#include<stdio.h>
using namespace std;

#include "Stack.h"

int main()
{
	Stack binaryDigits;
	int num=-1;

// get user input
	while (!cin || num<0){			
		cout <<"Enter a positive integer:  ";
		cin >> num;
		cin.clear();
		cin.ignore(10000,'\n');
	}

// display input as decimal
	cout <<"Decimal: "<<num<<endl;

// compute input as binary
	while (num != 0){
		binaryDigits.push(abs(num%2));
		num=num/2;
	}

// display binary
	cout <<"Binary: ";
	if (binaryDigits.empty())
		cout << "0";
	else{
		while (!binaryDigits.empty()){
				cout <<binaryDigits.top();
			binaryDigits.pop();
		}
	}
	cout <<endl;
}