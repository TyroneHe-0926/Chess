#include "chesspiece.h"

class King : public chessPiece {
    std::string chessType;
public:
    std::vector<std::pair<int, int>> getAvalibleMoves(std::pair<int, int>, Board&) override;
    std::string getType() override;
};