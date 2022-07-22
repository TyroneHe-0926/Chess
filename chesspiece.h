#include <vector>
#include <string>

class Board{};

class chessPiece{
public:
    virtual std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) = 0;
    virtual std::string getType() = 0;
};