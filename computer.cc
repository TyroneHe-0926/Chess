#include "computer.h"
#include "iostream"
using namespace std;

Computer::Computer(bool side, int diff) : side{side}, difficulty{diff}{}

int Computer::getDiff(){ return difficulty; }

bool Computer::getSide(){ return side; }

ChessMove Computer::getNextMove(Board*){
    std::cout << difficulty << std::endl;
    ChessMove result;
    if(difficulty == 49){
        result.first.first = (locationx)((rand()%8)+1);
        result.first.second = (rand()%8)+1;
        result.second.first = (locationx)((rand()%8)+1);
        result.second.second = (rand()%8);
    }
    std::cout << "(" << result.first.first << ", " << result.first.second 
        << "), (" << result.second.first << ", " << result.second.second << ")\n";
    //use our algorithm according to diff level to calculate the result and return
    return result;
}
