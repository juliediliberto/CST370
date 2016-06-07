/*	Title:  CST 370 Programming Assignment 2
	Author: Julia Diliberto
	ID:  002300804
	Date:  January 15, 2016
	File:  ProgAssign2.cpp
	Desc:  This program sorts a group of numbers using two stacks. It is tested on three different groups of numbers.
	Usage:  Other files required are Stack.cpp and Stack.h*/

#include <iostream>
using namespace std;

#include "Stack.h"

Stack sortStack(Stack stack1){
	Stack tempStack;
	int movedCount=0;
	int i=0;
	int temp;

	tempStack.push(stack1.top());
	stack1.pop();
	while (!stack1.empty()){ //process original 
		if (stack1.top() >= tempStack.top()){	
			tempStack.push(stack1.top());
			stack1.pop();
		}//end if
		else{
			temp = stack1.top();
			stack1.pop();
			while (!tempStack.empty() && tempStack.top() >= temp){
				stack1.push(tempStack.top());
				tempStack.pop();
				movedCount++;
			}//end while
			tempStack.push(temp);
			for (i=1; i<=movedCount; i++){
				tempStack.push(stack1.top());
				stack1.pop();
				}//end for
		}//end else
		movedCount=0;
	}//end while
	return tempStack;
}

int main()
{
   Stack stack1;
   Stack stack2;
   Stack stack3;

//FIRST TEST

//Initialize stack

	stack1.push(1);
	stack1.push(5);
	stack1.push(3);
	stack1.push(-3);
	stack1.push(4);
	stack1.push(8);
	stack1.push(10);
	stack1.push(-5);

//Process and display stack

	cout <<"First stack...\n";
    stack1.display(cout);
	stack1=sortStack(stack1);
	cout <<"\nAfter processing...\n";
	stack1.display(cout);

//SECOND TEST

//Initialize stack

	stack2.push(1);
	stack2.push(5);
	stack2.push(-4);
	stack2.push(-6);
	stack2.push(2);

//Process and display stack

	cout <<"Second stack...\n";
    stack2.display(cout);
	stack2=sortStack(stack2);
	cout <<"\nAfter processing...\n";
	stack2.display(cout);

//THIRD TEST

//Initialize stack

	stack3.push(1);
	stack3.push(5);
	stack3.push(-4);
	stack3.push(-6);
	stack3.push(2);

//Process and display stack

	cout <<"Third stack...\n";
    stack3.display(cout);
	stack3=sortStack(stack3);
	cout <<"\nAfter processing...\n";
	stack3.display(cout);

}