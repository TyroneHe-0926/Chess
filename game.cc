#include "game.h"
#include <string>
#include <iostream>
#include "types.h"
using namespace std;

Game::Game() : side{0}{}

void Game::play(){
    string command, p1, p2;
    ChessMove nextmove;
    bool started = false;
    int diff;
    while(cin>>command){
        if(command == "game"){
            cin>>p1>>p2;
            if(p1 == "human"){
                player1 = new Human{0};
            }
            else{
                diff = p1.back();
                player1 = new Computer{0, diff};
            }

            if(p2 == "human"){
                player2 = new Human{1};
            }
            else{
                diff = p2.back();
                player2 = new Computer{1, diff};
            }
            started = true;
            cout<<b<<endl;
        }
        if(command == "move" && started){
            if(side){
                nextmove = player2->getNextMove(b);
                b->nextMove(nextmove);
            }
            else{
                nextmove = player1->getNextMove(b);
                b->nextMove(nextmove);
            }
            side = !side;
        }
        else{
            cout<<"Game is not initalized yet!"<<endl;
        }
        if(command == "resign"){
            if(side){
                //player 1 wins
            }
            else{
                //player 2 wins
            }
        }
        if(command == "setup" && !started){
            b->init();
        }
        else{
            cout<<"No setup during a game!"<<endl;
        }
    }
}