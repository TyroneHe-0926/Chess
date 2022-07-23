#include "board.h"

bool Board::isWon(){
    return checkmate;
}

Board::Board(): grid{}, td{new TextDisplay}, checkmate{false} {
    for(int i = 1; i <= 8; ++i){
        grid.push_back({Cell({A,i}),
            Cell({B,i}), Cell({C,i}), Cell({D,i}), Cell({E,i}), 
            Cell({F,i}), Cell({G,i}), Cell({H,i})});
    }
}

Board::~Board(){
    delete td;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << pb.td;
}