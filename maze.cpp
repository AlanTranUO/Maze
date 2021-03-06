// Class automatically generated by Dev-C++ New Class wizard

#include "maze.h" // class's header file


#include <cstdlib>
#include <iostream>
#include "conio.h"

using namespace std;

// class constructor
Maze::Maze()
{ 
	// insert your code here
}

// class destructor
Maze::~Maze()
{
	// insert your code here
}

//Char LEGEND:
//219 = Walls
//255 = Blank Space
//233 = Hero
//232 = Key
//234 = Monster / Boss
//254 = Finish Line
//143 = Door
//'+' = health pot
//244 = weapon;
char Maze::mazeboard[12][12]=
 {//0  1   2   3   4   5   6   7   8   9  10  11
 219,219,219,219,219,219,219,219,219,219,219,219,//0
 219,233,219,234,255,219,255,255,255,255,'+',219,//1
 219,255,219,219,255,219,255,219,255,219,219,219,//2
 219,255,255,255,255,255,255,255,255,255,234,219,//3
 219,255,219,219,234,219,219,219,219,219,255,219,//4
 219,255,219,255,255,219,255,255,255,255,255,219,//5
 219,244,219,255,219,255,255,255,219,255,219,219,//6
 219,219,219,143,255,255,219,255,219,234,255,219,//7
 219,'+',255,255,219,219,219,244,219,255,234,219,//8
 219,219,219,255,234,255,255,219,255,219,232,219,//9
 219,219,'+',255,219,255,234,255,255,255,219,219,//10
 219,219,219,219,219,219,219,219,254,219,219,219,//11
 };
 
char Maze::mazeboard2[12][12]=
{//0  1   2   3   4   5   6   7   8   9  10  11
 219,219,219,219,219,219,219,219,219,219,219,219,//0
 219,233,219,255,255,219,255,255,255,255,255,219,//1
 219,255,219,219,255,219,255,219,255,219,219,219,//2
 219,255,255,255,255,255,255,255,255,219,255,219,//3
 219,255,219,219,255,219,219,219,219,219,255,219,//4
 219,255,219,255,255,219,255,255,255,255,255,219,//5
 219,255,219,255,219,255,255,255,219,255,219,219,//6
 219,219,219,255,255,255,219,255,219,255,255,219,//7
 219,255,255,255,219,219,219,255,219,255,255,219,//8
 219,219,219,255,143,255,255,219,255,219,232,219,//9
 219,219,255,255,219,255,255,255,255,255,219,219,//10
 219,219,219,219,219,219,219,219,255,219,219,219,//11
};


bool Maze::breadcrumb[12][12] = {false}; //False means Hero has not been there yet.

//FUNCTION DEFINITIONS --------------------------------------------------------------------------

void Maze::display_maze()
{ 
  for (int r =0; r<12; r++) //Row
  {
      for (int c =0; c<12; c++) //Column
      { cout<< mazeboard[r][c];
  
      }
      cout<<endl;
  }

}

void Maze::display_maze2()
{ 
    for (int r =0; r<12; r++) //Row
  {
      for (int c =0; c<12; c++) //Column
      { cout<< mazeboard2[r][c];
  
      }
      cout<<endl;
  }
}

//-----------------------------------------------------------------------------------------------


bool Maze::isWall(int row, int column) //If blankspace, return true
{
  if (mazeboard[row][column] == char (255))
  { 
    return true;
  }
  else
  {
    return false;
    
  }
}

//-----------------------------------------------------------------------------------------------

bool Maze::isWall2(int row, int column)
{
  if (mazeboard2[row][column] == char (255))
  { 
    return true;
  }
  
  else
  { return false;
  }
  
}

//-----------------------------------------------------------------------------------------------

bool Maze::isKey (int row, int column)
{
     if (mazeboard[row][column] == char (232))
     { 
       return true;
     }
     else
     { return false;
     }
}


//-----------------------------------------------------------------------------------------------

bool Maze::isKey2 (int row, int column)
{
     if (mazeboard2[row][column] == char (232))
     { 
       return true;
     }
     else
     { return false;
     }
}

//-----------------------------------------------------------------------------------------------

bool Maze::isDoor(int row, int column)
{
     
  if (mazeboard[row][column] == char (143))
  { 
    return true;
  }
  else
  { return false;
  }
  
  
}

//-----------------------------------------------------------------------------------------------

bool Maze::isDoor2 (int row, int column)
{
     if (mazeboard2[row][column] == char (143))
     { 
       return true;
     }
     else
     { return false;
     }
}


//-----------------------------------------------------------------------------------------------

bool Maze::isFinishLine (int row, int column)
{
    if ( mazeboard[row][column] == char (254) )
     { 
       return true;
     }
     
     else
     { return false;
     }
     
     
}

//-----------------------------------------------------------------------------------------------

bool Maze::isMonster(int row, int column)
{ 
     if ( mazeboard[row][column] == char (234) )
     { 
       return true;
     }
     
     else
     { return false;
     }
}


//-----------------------------------------------------------------------------------------------

bool Maze::isHealth(int row, int column)
{ 
     if ( mazeboard[row][column] == '+' )
     { 
       return true;
     }
     
     else
     { return false;
     }
}


bool Maze::isWeapon(int row, int column)
{ 
     if ( mazeboard[row][column] == char(244) )
     { 
       return true;
     }
     
     else
     { return false;
     }
}
