#include "textdisplay.h"
#include "cell.h"

TextDisplay::TextDisplay(){
    for(int i = 0; i < 8; i++){
        display.push_back(std::vector<char>(8, ' '));
    }
}

void TextDisplay::notify(Cell& c){
    Position temp = c.getCoords();
    char intoDisp;
    switch(c.getType().first){
        case PieceType::Pawn: intoDisp = 'P';
            break;
        case PieceType::Rook: intoDisp = 'R';
            break;
        case PieceType::Knight: intoDisp = 'N';
            break;
        case PieceType::Bishop: intoDisp = 'B';
            break;
        case PieceType::Queen: intoDisp = 'Q';
            break;
        case PieceType::King: intoDisp = 'K';
            break;
        default: intoDisp = (temp.first+temp.second)%2?' ':'_';
    }
    if(c.getType().second){
        intoDisp+=26;
    }
    display[((int)temp.first)-1][temp.second-1] = intoDisp;
}

std::ostream &operator<<(std::ostream& out, const TextDisplay& ptd){
    for(auto i: ptd.display){
        for(auto j: i){
            out << j;
        }
        out << std::endl;
    }
    return out;
}