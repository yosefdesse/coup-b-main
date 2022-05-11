#pragma once

#include <vector>
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    public:
        unsigned int turn_num;
        unsigned int sum_of_players;
        string the_winner;
        string current_turn = "";
        vector<Player *> players_list;
        // vector<string> card{"Duke" , "Assassin" , "Ambassador" , "Captain" , "Contessa"};
        // vector<string> players_list;

        Game();
        ~Game();
        void add_player(Player &player);
        void next_turn();
        unsigned int get_turn_num();
        vector<string> players();
        string turn();
        string winner();
        // friend std::ostream &operator<<(ostream &out, const vector<string> players);
    };
}