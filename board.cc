#include "board.h"

void Board::init(){

}

bool Board::isWon(){
    return checkmate;
}

void Board::nextMove(ChessMove move){
    //should handle deleting killed cells
    std::shared_ptr<ChessPiece> nextOccupant = nullptr;
    std::shared_ptr<ChessPiece>* temp = &nextOccupant;
    grid[8-move.first.second][((int)move.first.first)-1].setState(temp);
    grid[8-move.second.second][((int)move.second.first)-1].setState(temp);
}

Board::Board(): grid{}, td{new TextDisplay}, gui{new GUI}, checkmate{false} {
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
