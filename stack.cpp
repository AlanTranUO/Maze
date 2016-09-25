// Class automatically generated by Dev-C++ New Class wizard

#include "stack.h" // class's header file
#include "link.h"
#include <iostream>
using namespace std;


// class constructor
Stack::Stack()
{ size = 0;
	// insert your code here
}

// class destructor
Stack::~Stack()
{
	// insert your code here
}

//FUNCTION DEFFINITION

    void Stack::Push(char num)
    {   Link * link;
        link = new Link;
        link -> value = num;
        
       if (size > 0)
       { link -> prev = top;
        top = link;
        size ++;
       }
       
       else if (size == 0)
       { top = link;
        size ++;
       }
       

    } // add to the stack
    
    
    char Stack::pop()
    {  if  (size >1)
       {
        char temp;
        temp = top -> value;
        top = top -> prev;
        size = size -1;
        return temp;
       }
       
       if (size ==1)
       {char temp;
        temp =  top -> value;
        //top = null;
    
        size = size -1;
        return temp;
       }
       
       if (size <=0)
       {cout<<"I am sorry, you cannot do that." <<endl;
       }
      
    } //remove the last link frm the stack
    

    
    char Stack::peak()
    { return top->value;
    } // looks at top of stack without removing it.