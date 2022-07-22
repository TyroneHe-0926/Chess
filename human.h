#include "player.h"

class Human : public Player{
    int side;
public:
    int getSide() override;
    std::vector<std::pair<int, int>> getNextMove() override;
};