

// using namespace std;
// using namespace coup;
#include "Player.hpp"
#include "Duke.hpp"

namespace coup
{
    Duke::Duke(Game &game, string name) : Player(game, name)
    {
        this->my_role="Duke";
    }
    Duke::~Duke(){}

    void Duke::block(Player &player)
    {


        if (player.get_is_alive())
        {
            if (player.get_last_action() == "foreign_aid")
            {
                player.set_my_coins(-2);

            }
            if (player.get_last_action() != "foreign_aid")
            {

                throw("you can not block any operation except foreign_aid operation from players !!");
            }
        }
        else
        {
            throw("invalid operation you are not anymore in the game!!");
        }
    }

    void Duke::tax()
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        if (this->get_is_alive() ) 
        {
            this->set_my_coins(3);
        }
        else
        {
            throw(" the player are not in the game anymore ");
        }
        this->set_last_action("tax");
        this->my_game->next_turn();

        
    }
}