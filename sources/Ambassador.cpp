
// using namespace std;
// using namespace coup;
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Captain.hpp"

namespace coup
{
    Ambassador::Ambassador(Game game, string name) : Player(game, name)
    {
        this->my_role = "Ambassador";
    }
    Ambassador::~Ambassador() {}

    void Ambassador::block(Player &player)
    {

        if (player.role() != "Caption")
        {
            throw("invalid operation you can not block this player!!");
        }

        if (player.get_is_alive())
        {
            if (player.get_last_action() == "steal")
            {
                player.set_my_coins(-2);
                player.get_blocked_player().set_my_coins(2);


            }
            if (player.get_last_action() != "steal")
            {

                throw("you can not block any operation except steal from player  Captain !!");
            }
        }
        else
        {
            throw("invalid operation you are not anymore in the game!!");
        }

        // update_turns(this);
        // this->last_action = "block";
    }

    void Ambassador::transfer(Player &player_1, Player &player_2)
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        if ((player_1.get_is_alive()) && (player_2.get_is_alive() ))
        {
            if (player_1.coins() > 0)
            {
                player_1.set_my_coins(-1);
                player_2.set_my_coins(1);
            }
            else
            {
                throw("player_1 don't have any coins to take (player_1.coins = 0 )");
            }
        }
        else
        {
            throw("one or both of the player are not in the game");
        }
        this->set_last_action("transfer");
        this->my_game->next_turn();
    }
}