
// using namespace std;
// using namespace coup;
#include "Player.hpp"
#include "Game.hpp"
#include "Contessa.hpp"

namespace coup
{

    Contessa::Contessa(Game &game, string name) : Player(game, name)
    {
        this->my_role="Contessa";
    }
    Contessa::~Contessa() {}
    void Contessa::block(Player &player)
    {
        if(player.role() != "Assassion")
        {
            throw("invalid operation you can not block this player!!");
        }

        if(player.get_is_alive())
        {
            if (player.get_last_action() == "coup")
            {
                player.get_coup_player().set_is_alive(true);

            }
            if (player.get_last_action() != "coup")
            {

                throw("you can not block any operation except coup from player  Assassion !!");
            }
        }
        else
        {
            throw("invalid operation you are not anymore in the game!!");
        }
    }
    // void Contessa::tax() {}
}