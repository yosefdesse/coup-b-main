
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"



using namespace std;

namespace coup
{
    class Assassin : public Player
    {
        public:
        Assassin( Game game , string name )  ;
        ~Assassin();
        void coup(Player &player) override;


    };
}