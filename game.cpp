
// Class automatically generated by Dev-C++ New Class wizard

#include "game.h" // class's header file
#include <cstdlib>
#include <iostream>
#include "conio.h" //For bool
#include "maze.h"
#include <windows.h> //To use Sleep

using namespace std;
// class constructor
Game::Game()
{ 
 
	// insert your code here
 
 main_hero.themaze = new Maze;
 game_maze = *(main_hero.themaze);
 
 main_hero.themonster1 = new Monster;
 main_hero.themonster2 = new Monster;
 main_hero.themonster3 = new Monster;
 main_hero.themonster4 = new Monster;
 main_hero.themonster5 = new Monster;
 main_hero.themonster6 = new Monster;
 main_hero.theboss = new Monster;
 
 monster1 = main_hero.themonster1;
 monster2 = main_hero.themonster2;
 monster3 = main_hero.themonster3;
 monster4 = main_hero.themonster4;
 monster5 = main_hero.themonster5;
 monster6 = main_hero.themonster6;
 boss = main_hero.theboss;
 
 gamelooper =0;
 option = 0;

 
 //MONSTERS----------------
 
 //monster1
 monster1 ->set_name("Colosis");
 monster1 ->set_health(800);
 monster1 ->set_defence(10);
 monster1 ->set_damage(20);
 
 //monster2
 monster2 ->set_name("Demon Prince");
 monster2 ->set_health(1200);
 monster2 ->set_defence(5);
 monster2 ->set_damage(25);
 
 //monster3
 monster3 ->set_name("Tiger");
 monster3 ->set_health(2000);
 monster3 ->set_defence(50);
 monster3 ->set_damage(50);
 
 //monster4
 monster4 ->set_name("Omar");
 monster4 ->set_health(2500);
 monster4 ->set_defence(0);
 monster4 ->set_damage(80);
 
 //monster5
 monster5 ->set_name("Werewolf");
 monster5 ->set_health(3500);
 monster5 ->set_defence(10);
 monster5 ->set_damage(40);
 
 //monster6
 monster6 ->set_name ("Komiljon");
 monster6 ->set_health(5000);
 monster6 ->set_defence(50);
 monster6 ->set_damage(100);
 
 //BOSS
 boss ->set_name("GIANT BOSS");
 boss ->set_health(7000);
 boss ->set_defence(105);
 boss ->set_damage(150);
 
 //ITEMS
 
 healthpot1.set_name("Health Pot");
 healthpot1.set_effect(1);
 healthpot1.set_row(1);
 healthpot1.set_column(10);
 
 healthpot2.set_name("Health Pot");
 healthpot2.set_effect(1);
 healthpot2.set_row(8);
 healthpot2.set_column(1);
 
 
 healthpot3.set_name("Health Pot");
 healthpot3.set_effect(1);
 healthpot3.set_row(10);
 healthpot3.set_column(2);
 
 sword1.set_name ("Dragon Sword");
 sword1.set_damage (50);
 sword1.set_effect (2);
 sword1.set_row(6);
 sword1.set_column(1);
 
 sword2.set_name ("Winter Frost");
 sword1.set_damage (50);
 sword2.set_effect (2);
 sword2.set_row(8);
 sword2.set_column(7);
 

}

// class destructor
Game::~Game()
{
	// insert your code here
}

//FUNCTION DEFINITIONS --------------------------------------------------------------------------


void Game::intro()
{ 
 cout<<"LEFT 2 DIE      version: 2.07         Created By: Alan Tran 2016" <<endl<<endl;
 cout<<"START GAME (1)         INSTRUCTIONS(2)          EXIT GAME (3)"<<endl;
 cin>> option;
 if (option == 1)
 { system("cls");
   choosing_which_game();
 }
 else if (option == 2)
 { instructions();
 }
 else
 { cout<<"GAME IS EXITING"<<endl;
 }
 
}

//-----------------------------------------------------------------------------------------------

void Game::instructions()
{ cout<<endl;
  cout<<"ULTIMATE GOAL: ESCAPE THE MAZE ALIVE"<<endl;
  cout<<"Manual Solver:"<<endl;
  cout<<"Controls: W - Move up"<<endl;
  cout<<"          A - Move Left"<<endl;
  cout<<"          S - Move Down"<<endl;
  cout<<"          D - Move Right"<<endl;
  cout<<"There is a door ("<<char(143)<<") blocking the exit."<<endl;
  cout<<"But the door is locked and you will need to find a key ("<<char(232)<<") first to open it"<<endl;
  cout<<"Along your journey there will be monsters ("<<char(234)<<") that you must fight by moving towards it."<<endl;
  cout<<"But dont worry because there will be weapons ("<<char(244)<<") and health pots (+) that will save you."<<endl<<endl<<endl;
  cout<<"Auto Solver: Does everything for you! Just watch and enjoy!"<<endl;
  cout<<endl<<endl<<endl;
  cout<<"Please run game again and play. Good Luck MUHAHAHHA!"<<endl;
  
                
}


//-----------------------------------------------------------------------------------------------

void Game::choosing_which_game()
{ cout<<" USER GAME EXPERIENCE (1)   OR    AUTO BOT SOLVER(2)"<<endl;
  
  int optionloop = 1;
  
  while (optionloop == 1)
  { string option2;
    cin>> option2;
    
        if (option2 == "1")
        { system("cls");
         optionloop = 0;
         gamelooper = 1;
         playing_loop();
         //cout<<"You made it alive Hero!"<<endl;
         
        }
        else if (option2 == "2")
        { auto_solve();
          optionloop = 0;
        }
       
        else
        {cout<<"ERROR: Please give another input"<<endl;
        }
 }
  
}



//-----------------------------------------------------------------------------------------------


void Game::playing_loop()
{  game_maze.display_maze();
     while(gamelooper ==1)
     {  
        main_hero.move();
        display_stats();
        if ( (main_hero.get_health() <= 0) || (game_maze.mazeboard[11][8] == char(233) ) )
        { gamelooper = 0;
          if (main_hero.get_health() <= 0)
          { cout<<"You died!"<<endl;
            cout<<"You lose, please play again"<<endl;
          }
        }
     }
}


//-----------------------------------------------------------------------------------------------

void Game::display_stats() //Displays Hero stats, and displays both hero and monster stats if hero is next to monster
{  
   cout<<endl;
   //MONSTER 1
   if ( (main_hero.get_hero_row() == 1 && main_hero.get_hero_column() == 4) && (monster1 -> get_health() > 0) )
   { 
   display_monster_hero_stats(monster1);
   }
   
   //MONSTER 2
   else if( ( (main_hero.get_hero_row() == 3 && main_hero.get_hero_column() == 4) || (main_hero.get_hero_row() == 5 && main_hero.get_hero_column() == 4) ) && (monster2 -> get_health() > 0) )
   {
   display_monster_hero_stats(monster2);
   }
   
   //MONSTER 3
   else if ( ((main_hero.get_hero_row() == 3 && main_hero.get_hero_column() == 9) || (main_hero.get_hero_row() == 4 && main_hero.get_hero_column() == 10) ) && (monster3 -> get_health() > 0) )
   {  display_monster_hero_stats(monster3);
   }
   
   //MONSTER 4
   else if ( (main_hero.get_hero_row() == 6 && main_hero.get_hero_column() == 9 ) && (monster4 -> get_health() > 0) )
   { display_monster_hero_stats(monster4);
   }
   
   //MONSTER 5
   else if ( ((main_hero.get_hero_row() == 8 && main_hero.get_hero_column() == 9) || (main_hero.get_hero_row() == 7 && main_hero.get_hero_column() == 10) ) && (monster5 -> get_health() > 0) )
   {  display_monster_hero_stats(monster5);
   }
     
   //MONSTER 6
   else if ( (main_hero.get_hero_row() == 9 && main_hero.get_hero_column() == 3 ) && (monster6 -> get_health() > 0) )
   {  display_monster_hero_stats(monster6);
   }
     
   //BOSS
   else if ( ((main_hero.get_hero_row() == 10 && main_hero.get_hero_column() == 5) || (main_hero.get_hero_row() == 9 && main_hero.get_hero_column() == 6)) && (boss -> get_health() > 0) )
   {  display_monster_hero_stats(boss);
   }
   
   else
   {
   cout<<"HERO:"<<endl;
   cout<<"HP: " <<main_hero.get_health()<<endl;
   cout<<"Def: " <<main_hero.get_defence()<<endl;
   cout<<"Strength: " <<main_hero.get_damage()<<endl;
   cout<<"Items: "<<main_hero.get_item_count()<<endl<<endl;
   }
   
}

//-----------------------------------------------------------------------------------------------

void Game::display_monster_hero_stats(Monster* amonster)
{	Monster* tempmonster = amonster;
	cout<<"HERO:                  "<<tempmonster -> get_name() <<":"<<endl;
    cout<<"HP: " <<main_hero.get_health() <<"                HP: "<<tempmonster -> get_health()<<endl;
    cout<<"Def: " <<main_hero.get_defence()<<"               Def: "<<tempmonster -> get_defence()<<endl;
    cout<<"Strength: " <<main_hero.get_damage()<<"       Strength: " <<tempmonster -> get_damage()<<endl;
    cout<<"Items: "<<main_hero.get_item_count()<<endl<<endl;
}

//-----------------------------------------------------------------------------------------------

void Game::auto_solve()
{    
     system("cls");
     game_maze.display_maze2();
     first_load_stack();
     while (game_maze.mazeboard2[11][8] == char(255) )
     { 
	   Sleep(100);
       automove();
       system("cls");
       game_maze.display_maze2();
     }
     
     
}

//-----------------------------------------------------------------------------------------------
void Game::first_load_stack()
{  stack1.Push('R');
   stack1.Push('D');
   stack1.Push('L');
   stack1.Push('U');
}

//-----------------------------------------------------------------------------------------------
void Game::automove()
{ 
     
  if (stack1.peak() == 'U')
  { 
  	direction = stack1.peak();
  	
	if ( (game_maze.isWall2( main_hero.get_hero_row() -1, main_hero.get_hero_column() ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row() -1][main_hero.get_hero_column()] == false ) )
    { game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
	  main_hero.char_position2_w();
      stack1.pop();
      reload_stack();
    }
    else
    {
     stack1.pop();
    }
                    
  }
  else if (stack1.peak() == 'L')
  { 
    direction = stack1.peak();
    if ( (game_maze.isWall2( main_hero.get_hero_row(), main_hero.get_hero_column() -1 ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column() -1] == false ) )
    { game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
	  main_hero.char_position2_a();
      stack1.pop();
      reload_stack();
    }
    else
    {
     stack1.pop();
    }
       
  }
  else if (stack1.peak() == 'D')
  { 
  	direction = stack1.peak();
  	
    if ( (game_maze.isWall2( main_hero.get_hero_row() +1 , main_hero.get_hero_column() ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row() + 1][main_hero.get_hero_column()] == false ) )
    { game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
	  main_hero.char_position2_s();
      stack1.pop();
      reload_stack();
    }
    else if ( (game_maze.isKey2( main_hero.get_hero_row() +1 , main_hero.get_hero_column() ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row() + 1][main_hero.get_hero_column()] == false ) )
    { 
	  game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
	  main_hero.char_position2_s();
	  reset_breadcrumbs();
      reset_stacks();
      first_load_stack();
    	
	}
    
    else
    {
     stack1.pop();
    }
  }
  else if (stack1.peak() == 'R')
  {
  	direction = stack1.peak();
  	
    if ( (game_maze.isWall2( main_hero.get_hero_row() , main_hero.get_hero_column() +1 ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row() ][main_hero.get_hero_column() +1 ] == false ) )
    { game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
      main_hero.char_position2_d();
      stack1.pop();
      reload_stack();
      
    }
    
    else if ( (game_maze.isDoor2( main_hero.get_hero_row() , main_hero.get_hero_column() +1 ) == true) &&  (game_maze.breadcrumb[main_hero.get_hero_row() ][main_hero.get_hero_column() +1 ] == false ) && (game_maze.mazeboard2[9][10] == char(255)) )
    {
      game_maze.breadcrumb[main_hero.get_hero_row()][main_hero.get_hero_column()] = true;
      main_hero.char_position2_d();
      stack1.pop();
      reload_stack();
	}
    
    else
    {
     stack1.pop();
    }
    
    
  }
  
  else if (stack1.peak() == 'B')
  {  
     direction = stack2.peak();
     
     if (stack2.peak() == 'U')
     { main_hero.char_position2_w();
      
     }
     else if (stack2.peak() == 'L')
     { main_hero.char_position2_a();
     }
     else if (stack2.peak() == 'D')
     { main_hero.char_position2_s();
     }
     else if (stack2.peak() == 'R')
     { main_hero.char_position2_d();
     }
     stack2.pop();
     stack1.pop();
     
     
  }
}

//-----------------------------------------------------------------------------------------------

void Game::reload_stack()
{   if (direction == 'U')
    {  stack2.Push('D');
       stack1.Push('B');
       stack1.Push('R');
       stack1.Push('L');
       stack1.Push('U');
    }
    else if (direction == 'L')
    {  stack2.Push('R');
       stack1.Push('B');
       stack1.Push('D');
       stack1.Push('L');
       stack1.Push('U');
    }
    else if (direction == 'D')
    {  stack2.Push('U');
       stack1.Push('B');
       stack1.Push('R');
       stack1.Push('D');
       stack1.Push('L');
     
    }
    else if (direction == 'R')
    { stack2.Push('L');
      stack1.Push('B');
      stack1.Push('R');
      stack1.Push('D');
      stack1.Push('U');
    }
     
}

//-----------------------------------------------------------------------------------------------

void Game::reset_breadcrumbs()
{ 
  for (int r =0; r<12; r++) //Row
  {
      for (int c =0; c<12; c++) //Column
      { game_maze.breadcrumb[r][c] = false;
  
      }
      
  }
}

void Game::reset_stacks()
{
	while ( (stack1.size != 0) || (stack2.size != 0) )
	{ stack1.pop();
	  stack2.pop();
	}
	

}