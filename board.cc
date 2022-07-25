#include <string>
#include "board.h"
#include "iostream"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

bool Board::init(std::istream& in){
    std::shared_ptr<ChessPiece> clear(nullptr);
    std::string arg1, arg2, arg3;
    bool start = 0;
    bool valid = 0;
    std::string wking, bking;
    do{
        in >> arg1;
        if(arg1 == "+"){
            if(in >> arg2 >> arg3){
                if(arg2.size() == 1 && (toupper(arg2[0]) == 'P' ||
                        toupper(arg2[0]) == 'R' || toupper(arg2[0]) == 'N' || 
                        toupper(arg2[0]) == 'B' || toupper(arg2[0]) == 'Q' || 
                        toupper(arg2[0]) == 'K') && arg3.size() == 2 && '@' < toupper(arg3[0]) && 
                        toupper(arg3[0]) < 'I' && '0' < arg3[1] && arg3[1] < ':'){
                    std::shared_ptr<ChessPiece> addtoboard;
                    switch(toupper(arg2[0])){
                        case 'P':
                            addtoboard = std::make_shared<Pawn>(Pawn(isupper(arg2[0])));
                            break;
                        case 'R':
                            addtoboard = std::make_shared<Rook>(Rook(isupper(arg2[0])));
                            break;
                        case 'N':
                            addtoboard = std::make_shared<Knight>(Knight(isupper(arg2[0])));
                            break;
                        case 'B':
                            addtoboard = std::make_shared<Bishop>(Bishop(isupper(arg2[0])));
                            break;
                        case 'Q':
                            addtoboard = std::make_shared<Queen>(Queen(isupper(arg2[0])));
                            break;
                        case 'K':
                            addtoboard = std::make_shared<King>(King(isupper(arg2[0])));
                            break;
                    }
                    grid[arg3[0]-'A'][arg3[1] - '1'].setState(addtoboard);
                    if(arg3 == wking){wking.clear();}
                    else if(arg3 == bking){bking.clear();}
                }
                else{
                    std::cout << "Invalid input, should follow format + K e1" << std::endl;
                }
            }
            else{
                std::cout << "Invalid input, should follow format + K e1" << std::endl;
            }
        }
        else if(arg1 == "-"){
            in >> arg2;
            if(arg2.size() == 2 && '@' < toupper(arg2[0]) && 
                    toupper(arg2[0]) < 'I' && '0' < arg2[1] && arg2[1] < ':'){
                grid[arg2[0]-'A'][arg2[1] - '1'].setState(clear);
                if(arg2 == wking){wking.clear();}
                else if(arg2 == bking){bking.clear();}
            }
            else{
                std::cout << "Invalid input, should follow format - e1" << std::endl;
            }
        }
        else if(arg1 == "="){
            in >> arg2;
            if(arg2 == "white"){
                start = 0;
            }
            else if(arg2 == "black"){
                start = 1;
            }
            else{
                std::cout << "Invalid input, should be either \"= white\" or \"= black\"" << std::endl;
            }
        }
        if(!wking.empty() && !bking.empty()){
            valid = 1;
        }
    }while(arg1 != "done" && valid == 1);
    return start;
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
        grid.push_back({Cell({A,i},nullptr,{td,gui}),
            Cell({B,i},nullptr,{td,gui}), 
            Cell({C,i},nullptr,{td,gui}), 
            Cell({D,i},nullptr,{td,gui}), 
            Cell({E,i},nullptr,{td,gui}), 
            Cell({F,i},nullptr,{td,gui}),
            Cell({G,i},nullptr,{td,gui}), 
            Cell({H,i},nullptr,{td,gui})});
    }
}

Board::~Board(){
    delete td;
    delete gui;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    return out << *pb.td;
}
