#include "board.h"

bool Board::isWon(){
    return checkmate;
}

Board::Board(): grid{}, td{new TextDisplay}, checkmate{false} {
    
}

Board::~Board(){
    delete td;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << pb.td;
}