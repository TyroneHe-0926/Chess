#include "game.h"
#include <string>
#include <iostream>
#include "types.h"
using namespace std;

Game::Game() : b{nullptr}, side{0}, player1{nullptr}, player2{nullptr}, computer{0} {}


void Game::play(){
    string command, p1, p2;
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
            b = new Board{};
            cout<<*b<<endl;
        }
        else if(command == "move" && started){
            if(side){player2->getNextMove(b);}
            else{player1->getNextMove(b);}
            cout<<*b<<endl;
            side = !side;
            side ? cout << "Black's turn" << endl : cout << "White's turn" <<endl;
        }
        else if(command == "move" && !started){
            cout<<"Game is not initalized yet!"<<endl;
        }
        else if(command == "resign"){
            if(side){
                //player 1 wins
            }
            else{
                //player 2 wins
            }
        }
        else if(command == "setup" && !started){
            b->init();
        }
        else if(command == "setup" && started){
            cout<<"No setup during a game!"<<endl;
        }
    }
    delete b;
    delete player1;
    delete player2;
}

Game::~Game(){
    delete b;
    delete player1;
    delete player2;
}
