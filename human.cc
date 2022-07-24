#include "human.h"
#include <iostream>
#include <string>
using namespace std;

Human::Human(bool side) : side{side} {}
    
bool Human::getSide() { return side; }

locationx charToX(char src){
    locationx ret;
    switch(src){
        case 'A':
            ret = A;
            break;
        case 'B':
            ret = B;
            break;
        case 'C':
            ret = C;
            break;
        case 'D':
            ret = D;
            break;
        case 'E':
            ret = E;
            break;
        case 'F':
            ret = F;
            break;
        case 'G':
            ret = G;
            break;
        case 'H':
            ret = H;
            break;
    }
    return ret;
}

bool Human::checkMove(Board* b, ChessMove nextmove){
    vector<PossibleMoves> pm = b->getAllAvailableMoves(side, b);
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

bool inCheck(Board* b, bool side){
    //get all the possible moves the opponent can make
    vector<PossibleMoves> pm = b->getAllAvailableMoves(!side, b);

    //check if this side is in check
    for(auto m : pm){
        if(b->getType(m.start).second != side){
            for(auto d : m.destination){
                if(b->getType(d).first == PieceType::King){
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
            b->nextMove(result);
            if(inCheck(b, this->side)){
                cout<<"You cannot move that piece, your king is currently in check!"<<endl;
                ChessMove original = make_pair(pos2, pos1);
                b->nextMove(original);
                cin>>src;
                continue;
            }
            break;
        }
        cout << "Invalid move, try again\n";
        cin >> src;
    }
    if(!cin.eof()){
        //check if your opponent is currently in check after the move
        if(inCheck(b, !(this->side))){
            side ? cout<<"White is in check"<<endl : cout<<"Black is in check"<<endl;
        }
    }
    return result;
}
