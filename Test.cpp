#define CHECK DOCTEST_CHECK

#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;
using namespace doctest;



TEST_CASE("1")
{
	Game game_1{};
	CHECK_THROWS(game_1.turn()); // no one play now
    CHECK_THROWS(game_1.winner()); // no one to win now
    Ambassador ambassador{game_1 , "Adam"};
    Assassin assassin{game_1 , "Oren"};
    Captain captain{game_1 , "Ron"};
    Contessa contessa{game_1 , "Yaara"};
    Duke duke{game_1 , "Bar"};

	// /* check that each players start with 0 coins;*/
	CHECK( ambassador.coins() == 0);    //adam
	CHECK( assassin.coins() == 0);      //Oren
	CHECK( captain.coins() == 0);       //ron
	CHECK( contessa.coins() == 0);      //Yaara
	CHECK( duke.coins() == 0);          //Bar

	// first to add to game_1 is the first to start
	CHECK(game_1.turn() == "Adam"); // check if the first turn belong to  Adam
	CHECK_NOTHROW(duke.income());	 
	int duke_coins = duke.coins(); 
	CHECK(duke_coins == 0);
	ambassador.income();
	int ambassador_coins=ambassador.coins();
	CHECK(ambassador_coins == 1);
	// need to check who's next turn
	std::string Oren = game_1.turn(); 
	CHECK(Oren == "Oren");		  /* check for turn*/
    assassin.foreign_aid();
	int assassin_coins  = assassin.coins();
	CHECK(assassin_coins == 2);				 // check for coins			
	// check that income working!!
	CHECK_NOTHROW(assassin.income()); 

	CHECK(game_1.turn() ==  "Ron"); /*check the trun*/
	CHECK(captain.coins()  == 0);	
	captain.income();
	int captain_coins=captain.coins();
	CHECK(captain_coins == 1);
	CHECK_NOTHROW(captain.foreign_aid());
	
	CHECK_NOTHROW(ambassador.income()); 
	CHECK_THROWS(game_1.winner()); // the game still on

}

TEST_CASE(" 2 ")
{
	Game game_2{};
	Ambassador ambassador_1{game_2 , "David"};
    Assassin assassin_1{game_2 , "Kobi"};
    Captain captain_1{game_2 , "Morgan"};
    Contessa contessa_1{game_2 , "Noa"};
    Duke duke_1{game_2 , "Dobi"};
	CHECK( ambassador_1.coins() == 0);    //David
	CHECK( assassin_1.coins() == 0);      //Kobi
	CHECK( captain_1.coins() == 0);       //Morgan
	CHECK( contessa_1.coins() == 0);      //Noa
	CHECK( duke_1.coins() == 0);          //Dobi
	vector<string> the_players{"David", "Kobi" , "Morgan" , "Noa" , "Dobi"};
	string curr_play = game_2.turn();
	CHECK_NOTHROW(curr_play.compare("Dobi") );
	CHECK(curr_play.compare("David"));
	unsigned int i=0;
	// checking the players names
	for(string curr_name : game_2.players())
	{
		
		CHECK(curr_name.compare(the_players[i]));
		i++;
	}
	curr_play = game_2.turn();
	CHECK(curr_play.compare("David"));
	CHECK(game_2.players_list.size()==5);
    ambassador_1.income();
	assassin_1.foreign_aid();
	captain_1.income();
	contessa_1.income();
	duke_1.income();
	CHECK( ambassador_1.coins() == 1);    //David
	CHECK( assassin_1.coins() == 2);      //Kobi
	CHECK( captain_1.coins() == 1);       //Morgan
	CHECK( contessa_1.coins() == 1);      //Noa
	CHECK( duke_1.coins() == 1);          //Dobi
    ambassador_1.income();
	assassin_1.foreign_aid();
    CHECK( ambassador_1.coins() == 2);    //David
	CHECK( assassin_1.coins() == 4);      //Kobi
	captain_1.income();
	contessa_1.income();
	duke_1.income();
	ambassador_1.income();
	CHECK( captain_1.coins() == 2);       //Morgan
	CHECK( contessa_1.coins() == 2);      //Noa
	CHECK( duke_1.coins() == 2);          //Dobi
	CHECK( ambassador_1.coins() == 3);    //David
	// eliminate ambassador_1 from the game
	assassin_1.coup(ambassador_1);
	// check how many player are still plays
	CHECK(game_2.players_list.size()==4);

}
