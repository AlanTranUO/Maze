// Class automatically generated by Dev-C++ New Class wizard

#ifndef HERO_H
#define HERO_H

#include "character.h" // inheriting class's header file
#include "maze.h"
#include "monster.h"

// Child class of type Character
class Hero : public Character
{   private:
          int hero_row;
          int hero_column;
          int item_count;
          
	public:
        Maze* themaze;
        
        Monster* themonster1;
        Monster* themonster2;
        Monster* themonster3;
        Monster* themonster4;
        Monster* themonster5;
        Monster* themonster6;
        Monster* theboss;
        
        //VALUES FROM OTHER CLASSES
        
        int get_hero_row();
        int get_hero_column();
        
        void set_hero_row(int);
        void set_hero_column(int);
	   
	    int get_item_count();
	    void set_item_count(int);
		
		void move();
		
		void char_position_w();
        void char_position_a();
        void char_position_s();
        void char_position_d();
        
        void check_wall_w();
        void check_wall_a();
        void check_wall_s();
        void check_wall_d();
        
        void check_door_a();
        void check_door_s();
        
        void check_key_s();
        
        void check_finish_s();
        
        void check_monsters_w();
        void check_monsters_a();
        void check_monsters_s();
        void check_monsters_d();
        
        void fight();
        void exchange_health(Monster*);
        
        void check_health_a();
        void check_health_d();
        
        
        void check_weapon_s();
        
 //AUTO SOLVER FUNCTIONS
void char_position2_w();
void char_position2_a();
void char_position2_s();
void char_position2_d();



		// class constructor
		Hero();
		// class destructor
		~Hero();
};

#endif // HERO_H
