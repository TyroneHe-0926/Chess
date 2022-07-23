#include "board.h"

bool Board::isWon(){
    return checkmate;
}

Board::Board(): grid{}, td{new TextDisplay}, checkmate{false} {
    for(int i = 1; i <= 8; ++i){
        grid.push_back({Cell({A,i},{td,gui}), Cell({B,i},{td,gui}), 
            Cell({C,i},{td,gui}), Cell({D,i},{td,gui}), Cell({E,i},{td,gui}), 
            Cell({F,i},{td,gui}), Cell({G,i},{td,gui}), Cell({H,i},{td,gui})});
    }
}

void Board::init(){

}

Board::~Board(){
    delete td;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << *pb.td;
}