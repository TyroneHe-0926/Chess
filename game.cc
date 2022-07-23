#include "game.h"
#include <string>
#include <iostream>
#include "types.h"
using namespace std;

Game::Game() : side{0}{}

void Game::initGame(){
    string input;
    string p1, p2;
    int diff;
    while(cin>>input){
        if(input == "game"){
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
            break;
        }
        else{
            cout<<"Please initialize the game first!"<<endl;
        }
    }
}

void Game::play(){
    string command;
    chessmove nextmove;
    while(cin>>command){
        if(command == "move"){
            if(side){
                nextmove = player2->getNextMove(b);
            }
            else{
                nextmove = player1->getNextMove(b);
            }
            side = !side;
        }
        if(command == "resign"){
            if(side){
                //player 1 wins
            }
            else{
                //player 2 wins
            }
        }
        if(command == "setup"){
            b.init();
        }
    }
}