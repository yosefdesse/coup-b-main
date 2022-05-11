
#include <string>
#include "Game.hpp"
#include <vector>
#include "Player.hpp"


// using namespace coup;
using namespace std;

namespace coup
{
    class Duke : public Player
    {
        public: 
        Duke( Game &game , string name ) ; //: Player(game , name) ;
        ~Duke();
        void block(Player &player);
        void tax();

    };
}