#ifndef TYPE_H_
#define TYPE_H_
#include <utility>
#include <vector>

class Observer;

enum class PieceType{
    Pawn = 1,
    Rook = 2,
    Knight = 3,
    Bishop = 4,
    Queen = 5,
    King = 6,
    Empty = 0 // ChessPiece should not have this type. Cell.getType() should return this type though
};

enum PlayerType{human, computer};
enum locationx{A = 1,B = 2,C = 3,D = 4,E = 5,F = 6,G = 7,H = 8};

typedef std::pair<PieceType, bool> Piece;
typedef std::pair<locationx, int> Position;
typedef std::pair<Position, Position> ChessMove;
typedef std::pair<ChessMove, Piece> MoveInfo;
typedef std::pair<Observer*, Observer*> Observe;


struct PossibleMoves{
    Position start;
    std::vector<Position> destination;
};

locationx charToX(char src);

#endif
