
#ifndef EDGE_H
#define EDGE_H

#include "Game.hpp"

#include <exception>

#include <iostream>
#include <stdexcept>
#include <vector>

// using namespace coup;
using namespace std;

static int stat_number = 0;

namespace coup
{
    class Game;
    class Player
    {
    protected:
        bool is_alive;
        unsigned int turn_number;
        Player *blocked_player;
        Player *coup_player;
        string last_action;
        // bool my_turn;
        string my_name;
        string my_role;
        int my_coins;
        Game *my_game;

    public:
        Player(Game &game, string name);
        ~Player();
        string role();
        int coins();
        virtual void block(Player &player);
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        string get_name();
        // bool get_my_turn();
        // void set_my_turn(bool turn);
        void set_my_coins(int coins);
        // void reduce_coins(int coins);
        // void update_turns(Player &player);
        bool get_is_alive();
        void set_is_alive(bool status);
        unsigned int get_turn_number();
        string get_last_action();
        void set_last_action(string l_action);
        Player get_blocked_player();
        void set_blocked_player(Player &player);
        Player get_coup_player();
        void set_coup_player(Player &player);
    };
}
#endif