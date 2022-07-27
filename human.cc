#include "human.h"
#include <iostream>
#include <string>
using namespace std;

Human::Human(bool side) : side{side} {}
    
PlayerType Human::getPlayerType(){ return human; }

bool Human::checkMove(Board* b, ChessMove nextmove){
    vector<PossibleMoves> pm = b->getAllAvailableMoves(side);
    for(auto m : pm){
        if(m.start == nextmove.first){
            for(auto d: m.destination){
                if(d == nextmove.second){
                    return true;
                }
            }
        }
    }
    return false;
}

ChessMove Human::getNextMove(Board* b){
    Position pos1, pos2;
    string src, target;
    ChessMove result;
    while(cin>>src>>target){
        if((src.size() != 2 || target.size() != 2 ) || 
            !('@' < toupper(src.at(0)) && toupper(src.at(0)) < 'I' && 
            '@' < toupper(target.at(0)) && toupper(target.at(0)) < 'I')){
                if(!cin){return result;}
                cout<<"Invalid command. Should be of format 'move e2 e4'."<<endl;
                cin >> src;
                continue;
        }
        char cinx = toupper(src[0]), coutx = toupper(target[0]);
        locationx inx = charToX(cinx), outx = charToX(coutx);

        int iny = src[1] - '0', outy = target[1] - '0';
        pos1 = make_pair(inx, iny);
        pos2 = make_pair(outx, outy);
        result = make_pair(pos1, pos2);

        if(checkMove(b, result)){   
            b->testMove(result, true);
            if(b->inCheck(this->side)){
                cout<<"You cannot move that piece, your king is currently in check!"<<endl;
                ChessMove original = make_pair(pos2, pos1);
                b->badMove(original, true);
                cin>>src;
                continue;
            }
            if(pos2.second == 1 || pos2.second == 8){
                if(b->getType(pos2).first == PieceType::Pawn){
                    while(cin >> src){
                        if((src == "N" || src == "B" || src == "R" || src == "Q")){
                            b->promote(pos2, toupper(src[0]));
                            break;
                        }
                        else{
                            std::cout << "Invalid command, input should be N, B, R, or Q" << std::endl;
                        }
                    }
                }
            }
            break;
        }
        cout << "Invalid move, try again\n";
        cin >> src;
    }
    if(!cin.eof()){
        //check if your opponent is currently in check after the move
        if(b->inCheck(!(this->side))){
            side ? cout<<"White is in check"<<endl : cout<<"Black is in check"<<endl;
        }
        //if its checkmate
        if(checkMate(b, this->side)){
            //but nothing can actually capture the king, its stalemate
            if(checkStale(b, this->side)){
                ChessMove staleGame = make_pair(make_pair(A, -2), make_pair(A, -2));
                return staleGame;
            }
            //else you just won
            ChessMove endGame = make_pair(make_pair(A, -1), make_pair(A, -1));
            return endGame;
        }
    }
    return result;
}
