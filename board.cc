#include "board.h"
#include "iostream"

void Board::init(){

}

void Board::nextMove(ChessMove move){
    //should handle deleting killed cells
    std::shared_ptr<ChessPiece> nextOccupant(nullptr);
    grid[move.first.second-1][((int)move.first.first)-1].setState(nextOccupant);
    grid[move.second.second-1][((int)move.second.first)-1].setState(nextOccupant);
}

Piece Board::getType(Position temp){
    return grid[temp.second-1][((int)temp.first)-1].getType();
}

std::vector<PossibleMoves> Board::getAllAvailableMoves(bool side, Board*b){
    std::vector<PossibleMoves> list;
    for(auto i: grid){
        for(auto j: i){
            if(j.getType().first != PieceType::Empty && j.getType().second == side){
                list.push_back({j.getCoords(), j.getAvailableMoves(b)});
            }
        }
    }
    return list;
}

Board::Board(): grid{}, td{new TextDisplay}, gui{new GUI} {
    for(int i = 1; i <= 8; ++i){
        grid.push_back({Cell({A,i},{td,gui}), Cell({B,i},{td,gui}), 
            Cell({C,i},{td,gui}), Cell({D,i},{td,gui}), Cell({E,i},{td,gui}), 
            Cell({F,i},{td,gui}), Cell({G,i},{td,gui}), Cell({H,i},{td,gui})});
    }
}

Board::~Board(){
    delete td;
    delete gui;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << *pb.td;
}
