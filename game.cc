#include "game.h"
#include <string>
#include <iostream>
#include <sstream>
#include "types.h"
using namespace std;

Game::Game() : b{new Board()}, side{0}, checkmate{false}, player1{nullptr}, player2{nullptr}, 
                computer{0}, player1Score{0}, player2Score{0} {}

bool Game::isWon(){
    return checkmate;
}

void Game::play(){
    string command, p1, p2;
    bool started = false;
    int diff;
    int setup = 0;
    while(cin>>command){
        if(command == "game"){
            if(setup == 0){
                std::stringstream defaultinput;
                defaultinput << "+ r a8 + n b8 + b c8 + q d8 + k e8 + b f8 + n g8 + r h8 ";
                defaultinput << "+ p a7 + p b7 + p c7 + p d7 + p e7 + p f7 + p g7 + p h7 ";
                defaultinput << "+ P a2 + P b2 + P c2 + P d2 + P e2 + P f2 + P g2 + P h2 ";
                defaultinput << "+ R a1 + N b1 + B c1 + Q d1 + K e1 + B f1 + N g1 + R h1 ";
                defaultinput << "done ";
                b->init(defaultinput, 1);
            }
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
            cout<<*b<<endl;
        }
        else if(command == "move" && started){
            if(side){
                ChessMove theMove = player2->getNextMove(b);
                if(theMove.second.second == -1){
                    cout<<"Checkmate! Black player won!"<<endl;
                    ++player2Score;
                    started = false;
                    delete b;
                    b = new Board();
                    continue;
                }
            }
            else{
                ChessMove theMove = player1->getNextMove(b);
                if(theMove.second.second == -1){
                    cout<<"Checkmate! White player won!"<<endl;
                    ++player1Score;
                    started = false;
                    delete b;
                    b = new Board();
                    continue;
                }
            }
            if(cin.eof()){break;}
            cout<<*b<<endl;
            side = !side;
            side ? cout << "Black's turn" << endl : cout << "White's turn" <<endl;
        }
        else if(command == "move" && !started){
            cout<<"Game is not initalized yet!"<<endl;
        }
        else if(command == "resign"){
            if(side){
                ++player1Score;
                cout<<"White player won! Start a new game by using command 'game'! "<<endl;
            }
            else{
                ++player2Score;
                cout<<"Black player won! Start a new game by using command 'game'! "<<endl;
            }
            started = false;
        }
        else if(command == "setup" && !started){
            side = b->init(std::cin, 0);
            setup = 1;
        }
        else if(command == "setup" && started){
            cout<<"No setup during a game!"<<endl;
        }
    }
    cout<<"Final Score"<<endl;
    cout<<"White: "<<player1Score<<endl;
    cout<<"Black: "<<player2Score<<endl;
}

Game::~Game(){
    delete b;
    delete player1;
    delete player2;
}
