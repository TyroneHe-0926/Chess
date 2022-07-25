#include <cstdlib>
#include <ctime>
#include "game.h"
#include "sdl_wrap.h"

SDL_Runner r;

int main(){
    std::srand(std::time(0));
    Game game{};
    game.play();
    return 0;
}