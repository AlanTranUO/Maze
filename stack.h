// Class automatically generated by Dev-C++ New Class wizard

#ifndef STACK_H
#define STACK_H
#include "link.h"

/*
 * No description
 */
class Stack
{
 
	public:
		// class constructor
		Stack();
		// class destructor
		~Stack();
		
	Link* top; //points to the last link or top of stack.
    int size; // number of links in the stack
    void Push(char); // add to the stack
    char pop(); //remove the last link frm the stack
    char peak(); // looks at top of stack without removing it.
};

#endif // STACK_H
