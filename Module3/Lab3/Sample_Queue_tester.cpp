/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Queue.h"

int main ()
{

  ifstream myfile;
  Queue footNote;
  char  fileChar;

  myfile.open("Sample.txt", ios::out);

  if (myfile.is_open()){
	  while (myfile.peek() != EOF){ //not end of file
		fileChar=myfile.get(); //read a character
		if (fileChar=='{'){ //look for footnote beginning marker
		   fileChar=myfile.get(); //get next character
		   while(fileChar != '}'){  //if it's not footnote ending marker
			   footNote.enqueue(fileChar); //store it
			   fileChar=myfile.get();  //get next character
		   }
	   }
	 }
	 while (!footNote.empty()){
		 fileChar=footNote.front();
		 cout<<fileChar;
		 footNote.dequeue();
	 }
	 cout<<endl;
	 myfile.close();
  }

  else cout << "Unable to open file"; 
  
}
