#include "human.h"
#include <iostream>
#include <string>
using namespace std;

Human::Human(bool side) : side{side} {}
    
bool Human::getSide() { return side; }

ChessMove Human::getNextMove(Board&){
    Position pos1, pos2;
    string src, target;
    ChessMove result;
    cin>>src>>target;
    
    while((src.size() != 2 || target.size() != 2 ) && 
        '@' < toupper(src.at(0)) && toupper(src.at(0)) < 'I' && 
        '@' < toupper(target.at(0)) && toupper(target.at(0)) < 'I'){
            cout<<"Invalid command. Should be of format 'move e2 e4'."<<endl;
            cin>>src>>target;
    }

    locationx inx = (locationx) toupper(src[0] - '@');
    locationx outx = (locationx) toupper(target[0] - '@');
    int iny = src[1], outy = target[1];
    pos1 = make_pair(inx, iny);
    pos2 = make_pair(outx, outy);
    result = make_pair(pos1, pos2);

    return result;
}
