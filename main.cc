#include <cstdlib>
#include <ctime>
#include "game.h"

int main(){
    std::srand(std::time(0));
    Game game{};
    game.play();
    return 0;
}