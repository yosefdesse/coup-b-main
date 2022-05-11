

// using namespace std;
// using namespace coup;
#include "Player.hpp"
#include "Game.hpp"
#include "Captain.hpp"

namespace coup
{

    Captain::Captain(Game game, string name) : Player(game, name)
    {
        this->my_role = "Captain";
    }
    Captain::~Captain() {}

    void Captain::steal(Player &player)
    {
        if ((this->get_is_alive() ) && (player.get_is_alive() ))
        {
            if (this->get_turn_number() == this->my_game->get_turn_num())
            {
                this->set_my_coins(2);
                player.set_my_coins(-2);
                this->set_last_action("steal");
                this->my_game->next_turn();
            }
            else
            {
                throw("you can not do this operation");
            }
        }
        this->set_last_action("steal");
        this->my_game->next_turn();
    }

    void Captain::block(Player &player)
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

    }

    // Player& Captain::get_im_stole_from()
    // {
    //     return im_stole_from;
    // }

    // void Captain::set_im_stole_from(Player &player)
    // {
    //     this->im_stole_from = &player;
    // }
}