

#include "Game.hpp"
using namespace std;

namespace coup
{

    Game::Game()
    {
        this->turn_num = 0;
        this->the_winner = "";
        this->current_turn = "";
        this->sum_of_players=0;
    }

    vector<string> Game::players()
    {
        vector<string> list_name;
        for (auto *temp : this->players_list)
        {
            list_name.push_back(temp->get_name());
        }
        return list_name;
    }

    string Game::turn()
    {
        return this->current_turn;
    }

    string Game::winner()
    {
        if (this->players_list.size() == 1)
        {
            this->the_winner = this->players_list[0]->get_name();
        }
        else
        {
            if (this->players_list.empty())
            {
                throw(" no one are playing");
            }
            else
            {
                throw("the game is still on");
            }
        }
        return this->the_winner;
    }

    Game::~Game() {}

    void Game::next_turn()
    {
        unsigned int temp_num = turn_num;

        // do
        // {
        //     this->turn_num = (turn_num + 1) % players_list.size();
        // }
        while (players_list[turn_num % players_list.size()]->get_is_alive())
        {
            this->turn_num = (turn_num + 1) % players_list.size();
        }
    }

    unsigned int Game::get_turn_num()
    {
        return this->turn_num;
    }

    void Game::add_player(Player &player)
    {
        this->players_list.push_back(&player);
        this->sum_of_players++;
    }

    // friend std::ostream &operator<<(ostream &out, const vector<string> players){ }
}