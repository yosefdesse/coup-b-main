
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"





using namespace std;

namespace coup
{
    class Contessa : public Player
    {
        public:
        Contessa( Game &game , string name ) ;
        ~Contessa();
        void block(Player &player);
        // void tax();

    };
}