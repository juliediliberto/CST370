/*	Title:  CST 370 Programming Assignment 1
	Author: Julia Diliberto
	ID:  002300804
	Date:  January 10, 2016
	File:  ProgAssign1_Tester.cpp

	Desc:  This program prompts the user for a string of characters
		It then analyzes the string for substrings which start with
		'A' and end with 'B'.  It displays those substrings and the total
		count of substrings.
	Usage:  Other files required are LinkedList.cpp and LinkedList.h*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   LinkedList charList;
   char userChar = 'Q';
   int index=0;
   int count=0;
  
  
//Get a list of characters from the user

   cout << "\nENTER A SUBSTRING:  ";

   userChar=cin.get();
   while (userChar != '\n'){
	   charList.insert(userChar, index);
	   index++;
	   userChar=cin.get();
   }
   charList.display(cout);
   cout << endl;

//Count and display substrings that start with A and end with B
   count=charList.analyzeList();

//Display count
   cout << "THERE ARE "<<count<<" SUBSTRINGS.\n";


  
}