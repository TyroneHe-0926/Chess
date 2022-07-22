#include "board.h"

bool Board::isWon(){
    return checkmate;
}

Board::~Board(){
    delete td;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << pb.td;
}