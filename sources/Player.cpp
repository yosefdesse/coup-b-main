// using namespace std;
// using namespace coup;
#include "Player.hpp"

namespace coup
{

    Player::Player(Game &game, string name)
    {
        this->is_alive = true;
        this->my_name = name;
        this->my_coins = 0;
        this->my_game = &game;
        // this->my_role = game.card[stat_number % 5];
        // this->my_turn = false;
        this->last_action = "";
        this->blocked_player = nullptr;
        this->coup_player=nullptr;
        this->turn_number = game.turn_num;
        game.turn_num++;
        game.add_player(*this);
        // if (game.players_list.empty())
        // {
        //     game.players_list.push_back(this);
        //     game.current_turn = name;
        //     this->my_turn = true;
        // }
        // else
        // {
        //     game.players_list.push_back(name);
        // }
    }

    Player::~Player() {}

    string Player::role()
    {
        return this->my_role;
    }

    int Player::coins()
    {
        return this->my_coins;
    }

    void Player::block(Player &player)
    {

        throw("you don't have the permission to use this operation");
        // if (this->get_my_turn() == false)
        // {
        //     throw("invalid operation is not your turn!!");
        // }
        // if (this->get_status == false)
        // {
        //     throw("invalid operation you are not anymore in the game!!");
        // }

        // // update_turns(this);
        // this->last_action = "block";
    }

    void Player::income()
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        this->my_coins++;
        this->last_action = "income";
        my_game->next_turn();
    }

    void Player::foreign_aid()
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        this->my_coins += 2;
        this->last_action = "foreign_aid";
        my_game->next_turn();
    }

    void Player::coup(Player &player)
    {
        if (this->get_turn_number() != this->my_game->get_turn_num())
        {
            throw("invalid operation is not your turn!!");
        }
        if (!player.get_is_alive())//(player.get_is_alive() == false)
        {
            throw("invalid operation the player you want to coup is not in the game!!");
        }
        if (this->my_coins < 7)
        {
            throw invalid_argument("this operation are not valid , you should have more than 7 coins to use this operation");
        }
        player.set_is_alive(false);
        this->last_action = "coup";
        my_game->next_turn();
    }

    string Player::get_name()
    {
        return this->my_name;
    }

    void Player::set_my_coins(int coins)
    {
        this->my_coins += coins;
    }

    // void Player::reduce_coins(int coins)
    // {
    //     this->my_coins -= coins;
    // }

    bool Player::get_is_alive()
    {
        return this->is_alive;
    }

    void Player::set_is_alive(bool status)
    {
        this->is_alive = status;
    }

    // bool Player::get_my_turn()
    // {
    //     return this->my_turn;
    // }

    // void Player::set_my_turn(bool turn)
    // {
    //     this->my_turn = turn;
    // }

    unsigned int Player::get_turn_number()
    {
        return this->turn_number;
    }

    string Player::get_last_action()
    {
        return this->last_action;
    }
    void Player::set_last_action(string l_action)
    {
        this->last_action = l_action;
    }

    Player Player::get_blocked_player()
    {
        return *this->blocked_player;
    }

    void Player::set_blocked_player(Player &player)
    {
        this->blocked_player = &player;
    }

    Player Player::get_coup_player()
    {
        return *this->coup_player;
    }

    void Player::set_coup_player(Player &player)
    {
        this->coup_player=&player;
    }

    // void Player::update_turns(Player &player)
    // {
    //     // string player_name=this->my_game->current_turn;
    //     // iterator it = this->my_game->players_list.begin();
    //     // this->my_game->players_list.erase(it);
    //     // this->my_game->current_turn = this->my_game->players_list.front();
    //     // this->my_game->players_list.push_back(player_name);
    // }

}