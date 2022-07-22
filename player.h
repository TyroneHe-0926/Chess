#include <vector>

class Player {
public:
    virtual int getSide() = 0;
    virtual std::vector<std::pair<int, int>> getNextMove() = 0;
};