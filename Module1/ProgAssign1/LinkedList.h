/*	Title:  CST 370 Programming Assignment 1
	Contributor: Julia Diliberto
	ID:  002300804
	Date:  January 10, 2016
	File:  LinkedList.h*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef char ElementType;

class LinkedList
{ 
private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	};
	Node * first;
	int mySize;

public:
	LinkedList();   // constructor
	~LinkedList();  // destructor
	LinkedList(const LinkedList & original); //copy constructor
	void insert(ElementType item, int pos);
	void erase(int item);
	int analyzeList(); //counts and displays substrings that start with A and end with B
	void display(ostream & out) const;
	/*--------------------------------------------------------------------
	Display the contents of this LinkedList.
	Precondition: ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/
	void display(ostream & out, Node * start, Node * stop) const;
	/*---------------------------------------------------------------------
	Display the contents of this Linked List between start and stop, inclusive.
	Precondition:  ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	---------------------------------------------------------------------*/


};

#endif

