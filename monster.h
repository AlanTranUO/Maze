// Class automatically generated by Dev-C++ New Class wizard

#ifndef MONSTER_H
#define MONSTER_H

#include "character.h" // inheriting class's header file
// Child class of Character 

class Monster : public Character
{   private:
    int monster_number; //Each monster has their own unique id.
    
	public:
		// class constructor
		Monster();
		// class destructor
		~Monster();
};

#endif // MONSTER_H
