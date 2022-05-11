#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Captain : public Player
    {
    private:
        // Player *im_stole_from;

    public:
        Captain(Game game, string name);
        ~Captain();
        // Player *get_im_stole_from();
        // void set_im_stole_from(Player &player);
        void steal(Player &player);
        void block(Player &player);
    };
}