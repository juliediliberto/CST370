/*	Title:  CST 370 Lab 2
	Author: Julia Diliberto
	ID:  002300804
	Date:  January 17, 2016
	File:  Lab2.cpp

	Desc:  This program will take a string as input from the user, display 
		that string and display the reverse of the string.
		result
	Usage:  Other files required are Stack.cpp and Stack.h*/

#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
	char userChar;
	Stack charStack;
	Stack reverseStack;

// prompt user for input and get string
	cout <<"Enter a string: ";
	userChar=cin.get();
	while (userChar != '\n'){
	   charStack.push(userChar);
	   userChar=cin.get();
	}

// display string
	cout << "You entered: ";
	while (!charStack.empty()){  //move elements to another stack
		reverseStack.push(charStack.top());
		charStack.pop();
	}
	while (!reverseStack.empty()){ //display the elements of this new stack
		cout<<reverseStack.top();
		charStack.push(reverseStack.top());
		reverseStack.pop();
	}
	cout << endl;

// display string in reverse
	cout<<"Reverse is: ";
	while (!charStack.empty()){
		cout<<charStack.top();
		reverseStack.push(charStack.top());
		charStack.pop();
	}
	cout <<endl;

// rebuild string
	while (!reverseStack.empty()){
		charStack.push(reverseStack.top());
		reverseStack.pop();
	}
}
