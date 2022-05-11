#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"



using namespace std;

namespace coup
{
    class Ambassador : public Player
    {
        public:
        Ambassador( Game game , string name );
        ~Ambassador();
        // void tax();
        void block(Player &player);     
        void transfer(Player &player_1 ,Player &player_2 );

    };
}