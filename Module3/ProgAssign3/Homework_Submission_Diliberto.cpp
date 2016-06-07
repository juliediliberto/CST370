/*	Title:  CST 370 Programming Assignment 3
	Author: Julia Diliberto
	ID:  002300804
	Date:  January 22, 2016
	File:  Homework_Submission_Diliberto.cpp
	Desc:  This program will take a string as input and determine 
		whether or not the string is a palindrome.
	Usage:  Other files required are Stack.cpp and Stack.h*/

#include <iostream>
using namespace std;
#include "Queue.h"
#include "Stack.h"

int main(){

	char userChar=' ';
	Queue myQueue;
	Stack myStack;

//get string from user
	cout<<"Enter a string: ";
	userChar=cin.get();
	while (userChar!='\n'){
		myQueue.enqueue(userChar); //insert each character into myQueue
		myStack.push(userChar);	//insert each character into myStack
		userChar=cin.get();
	}

	while (!myQueue.empty() && myQueue.front()==myStack.top()){ //there are remaining characters 
																//and first and last letters are the same
		myQueue.dequeue();  //remove one character from the queue
		myStack.pop();  //remove one character from the stack
	}
	if (myQueue.empty()) //all characters have been checked
		cout << "That is a palindrome\n";
	else  //different letters were found
		cout << "That is not a palindrome\n";

}