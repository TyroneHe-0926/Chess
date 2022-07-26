#include <string>
#include "board.h"
#include "iostream"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

bool Board::init(std::istream& in, bool def){
    std::string arg1, arg2, arg3;
    bool start = 0;
    bool valid = 0;
    do{
        in >> arg1;
        if(in.eof()){break;}
        if(arg1 == "+"){
            if(in >> arg2 >> arg3 && arg2.size() == 1 && (toupper(arg2[0]) == 'P' ||
                    toupper(arg2[0]) == 'R' || toupper(arg2[0]) == 'N' || 
                    toupper(arg2[0]) == 'B' || toupper(arg2[0]) == 'Q' || 
                    toupper(arg2[0]) == 'K') && arg3.size() == 2 && '@' < toupper(arg3[0]) && 
                    toupper(arg3[0]) < 'I' && '0' < arg3[1] && arg3[1] < ':'){
                std::shared_ptr<ChessPiece> addtoboard;
                switch(toupper(arg2[0])){
                    case 'P':
                        addtoboard = std::make_shared<Pawn>(Pawn(islower(arg2[0])));
                        break;
                    case 'R':
                        addtoboard = std::make_shared<Rook>(Rook(islower(arg2[0])));
                        break;
                    case 'N':
                        addtoboard = std::make_shared<Knight>(Knight(islower(arg2[0])));
                        break;
                    case 'B':
                        addtoboard = std::make_shared<Bishop>(Bishop(islower(arg2[0])));
                        break;
                    case 'Q':
                        addtoboard = std::make_shared<Queen>(Queen(islower(arg2[0])));
                        break;
                    case 'K':
                        addtoboard = std::make_shared<King>(King(islower(arg2[0])));
                        break;
                }
                grid[arg3[1] - '1'][toupper(arg3[0])-'A'].setState(addtoboard);
                if(def == 0){
                    std::cout << *td;
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
                if(grid[arg2[1] - '1'][toupper(arg2[0])-'A'].getType().first != PieceType::Empty){
                    std::shared_ptr<ChessPiece> nullchess(nullptr);
                    grid[arg2[1] - '1'][toupper(arg2[0])-'A'].setState(nullchess);
                    if(def == 0){
                        std::cout << *td;
                    }
                }
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
        else if(arg1 == "done"){
            valid = 1;
            for(int i = 0; i < 8; i++){
                if(grid[0][i].getType().first == PieceType::Pawn || 
                        grid[7][i].getType().first == PieceType::Pawn){
                    std::cout << "Invalid setup, pawns are not allowed in the first and last rows" << std::endl;
                    valid = 0;
                }
            }
            int numWKing = 0;
            int numBKing = 0;
            for(auto i: grid){
                for(auto j: i){
                    Piece k = j.getType();
                    if(k.first == PieceType::King && k.second == 0){
                        numWKing++;
                    }
                    else if(k.first == PieceType::King && k.second == 1){
                        numBKing++;
                    }
                }
            }
            if(numBKing != 1 || numWKing != 1){
                std::cout << "Invalid setup, there must be 1 king for each side" << std::endl;
                valid = 0;
            }
            if(inCheck(0) || inCheck(1)){
                std::cout << "Invalid setup, a king is in check" << std::endl;
                valid = 0;
            }
            
        }
        else{std::cout << "Invalid command" << std::endl;}
    }while(arg1 != "done" || valid == 0);
    return start;
}

bool Board::inCheck(bool side){
    //get all the possible moves the opponent can make
    std::vector<PossibleMoves> pm = getAllAvailableMoves(!side);

    //check if this side is in check
    for(auto m : pm){
        if(getType(m.start).second != side){
            for(auto d : m.destination){
                if(getType(d).first == PieceType::King){
                    return true;
                }
            }
        }
    }
    return false;
}


void Board::enPassant(ChessMove move){
    //ensure that this is only triggered if the source piece is a pawn, the destination is diagonal,
    //and the destination is empty
    std::shared_ptr<ChessPiece> clearpawn(nullptr);
    Piece a = grid[move.first.second-1][((int)move.first.first)-1].getType();
    Piece dest = grid[move.second.second-1][((int)move.second.first)-1].getType();
    Position s = move.first;
    Position d = move.second;
    if(a.first == PieceType::Pawn && dest.first == PieceType::Empty 
            && (s.second+1 == d.second || s.second-1 == d.second)
            && (s.first+1 == d.first || s.first-1 == d.first)){
        Piece b;
        if(a.second){
            b = grid[move.second.second][((int)move.second.first)-1].getType();
            if(b.first == PieceType::Pawn){
                grid[move.second.second][((int)move.second.first)-1].setState(clearpawn);
            }
        }
        else{
            b = grid[move.second.second-2][((int)move.second.first)-1].getType();
            if(b.first == PieceType::Pawn){
                grid[move.second.second-2][((int)move.second.first)-1].setState(clearpawn);
            }
        }
    }
}


void Board::castling(ChessMove move){
    std::shared_ptr<ChessPiece> nextOccupant(nullptr);
    if(move.second.first+2 == move.first.first){
        grid[move.first.second-1][0].setState(nextOccupant);
        grid[move.first.second-1][3].setState(nextOccupant);
    }
    else if(move.second.first-2 == move.first.first){
        grid[move.first.second-1][7].setState(nextOccupant);
        grid[move.first.second-1][5].setState(nextOccupant);
    }
    
}

void Board::nextMove(ChessMove move, bool update){
    //should handle deleting killed cells
    std::shared_ptr<ChessPiece> nextOccupant(nullptr);
    if(update){
        list.AddMove(move, getType(move.first), getType(move.second));
        //en passant
        enPassant(move);
        if(grid[move.first.second-1][((int)move.first.first)-1].getType().first == PieceType::King){
            castling(move);
        }
    }
    grid[move.first.second-1][((int)move.first.first)-1].setState(nextOccupant);
    grid[move.second.second-1][((int)move.second.first)-1].setState(nextOccupant);
}

void Board::testMove(ChessMove move, bool update){
    if(!update){
        grid[move.first.second-1][((int)move.first.first)-1].movent();
        grid[move.first.second-1][((int)move.first.first)-1].movent();
    }
    grid[move.second.second-1][((int)move.second.first)-1].test();
    nextMove(move, update);
}

void Board::badMove(ChessMove move, bool update){
    nextMove(move, false);
    if(update){
        grid[move.first.second-1][((int)move.first.first)-1].movent();
        list.getLastMove();
    }
    grid[move.first.second-1][((int)move.first.first)-1].undo();
}

ChessMove Board::lastMove(){
    return list.readLastMove();
}

Piece Board::getType(Position temp){
    return grid[temp.second-1][((int)temp.first)-1].getType();
}

int Board::moved(Position temp){
    return grid[temp.second-1][((int)temp.first)-1].moved();
}

std::vector<PossibleMoves> Board::getAllAvailableMoves(bool side){
    std::vector<PossibleMoves> list;
    for(auto i: grid){
        for(auto j: i){
            if(j.getType().first != PieceType::Empty && j.getType().second == side){
                list.push_back({j.getCoords(), j.getAvailableMoves(this)});
            }
        }
    }
    return list;
}

void Board::promote(Position p, char c){
    std::shared_ptr<ChessPiece> nextOccupant;
    switch(c){
        case 'Q':
            nextOccupant = std::make_shared<Queen>(Queen(getType(p).second));
            break;
        case 'N':
            nextOccupant = std::make_shared<Knight>(Knight(getType(p).second));
            break;
        case 'R':
            nextOccupant = std::make_shared<Rook>(Rook(getType(p).second));
            break;
        case 'B':
            nextOccupant = std::make_shared<Bishop>(Bishop(getType(p).second));
            break;
        default:
            break;
    }
    grid[p.second-1][p.first-1].setState(nextOccupant);
}

Board::Board(): grid{}, td{new TextDisplay}, gui{new GUI()} {
    for(int i = 1; i <= 8; ++i){
        grid.push_back({Cell({A,i},nullptr,td),
            Cell({B,i},nullptr,td), 
            Cell({C,i},nullptr,td), 
            Cell({D,i},nullptr,td), 
            Cell({E,i},nullptr,td), 
            Cell({F,i},nullptr,td),
            Cell({G,i},nullptr,td), 
            Cell({H,i},nullptr,td)});
    }
    gui->update(td);
}

Board::~Board(){
    delete gui;
    delete td;
}

std::ostream& operator<<(std::ostream& out, Board& pb){
    pb.gui->update(pb.td);
    return out << *pb.td;
}
