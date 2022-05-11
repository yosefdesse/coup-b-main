
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"

namespace coup
{

    Assassin::Assassin(Game game, string name) : Player(game, name) 
    {
        this->my_role="Assassin";
    }

    Assassin::~Assassin() {}
    
    void Assassin::coup(Player &player)
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        if (!player.get_is_alive())
        {
            throw("invalid operation the player you want to coup is not in the game!!");
        }
        if (this->my_coins < 3)
        {
            throw invalid_argument("this operation are not valid , you should have more than 2 coins to use this operation");
        }
        player.set_is_alive(false);
        this->set_last_action("coup");
        this->my_game->next_turn();
    }
}