#include "game.h"
#include <string>
#include <iostream>
#include <sstream>
#include "types.h"
using namespace std;

Game::Game() : b{new Board()}, side{0}, checkmate{false}, started{false}, player1{nullptr}, player2{nullptr}, 
                computer{0}, player1Score{0}, player2Score{0}{}

bool Game::isWon(){
    return checkmate;
}

void Game::endGame(char status){
    if(status == 'g'){
        if(side){
            cout<<"Checkmate! Black player won!"<<endl;
            ++player2Score;
        }
        else{
            cout<<"Checkmate! White player won!"<<endl;
            ++player1Score;
        }
    }
    if(status == 's'){
        cout<<"Draw game!"<<endl;
        player1Score+=0.5;
        player2Score+=0.5;
    }
    started = false;
    delete b;
    b = new Board{};
    side = 0;
}


void Game::play(){
    string command, p1, p2;
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
            if(player1){ delete player1; }
            if(player2){ delete player2; }
            if(p1 == "human"){
                player1 = new Human{0};
            }
            else{
                diff = p1.back() - '0';
                player1 = new Computer{0, diff};
            }

            if(p2 == "human"){
                player2 = new Human{1};
            }
            else{
                diff = p2.back() - '0';
                player2 = new Computer{1, diff};
            }
            started = true;
            cout<<*b<<endl;
        }
        if(started){
            if(command == "move"){
                if(!side && player1->getPlayerType() == PlayerType::computer){
                    cout<<"White computer is making a move"<<endl;
                    ChessMove theMove = player1->getNextMove(b);
                    if(theMove.second.second == -1){
                        endGame('g');
                        continue;
                    }
                    if(theMove.second.second == -2){
                        endGame('s');
                        continue;
                    }
                }
                if(side && player2->getPlayerType() == PlayerType::computer){
                    cout<<"Black computer is making a move"<<endl;
                    ChessMove theMove = player2->getNextMove(b);
                    if(theMove.second.second == -1){
                        endGame('g');
                        continue;
                    }
                    if(theMove.second.second == -2){
                        endGame('s');
                        continue;
                    }
                }
                if(side && player2->getPlayerType() == PlayerType::human){
                    ChessMove theMove = player2->getNextMove(b);
                    if(theMove.second.second == -1){
                        endGame('g');
                        continue;
                    }
                    if(theMove.second.second == -2){
                        endGame('s');
                        continue;
                    }
                }
                if(!side && player1->getPlayerType() == PlayerType::human){
                    ChessMove theMove = player1->getNextMove(b);
                    if(theMove.second.second == -1){
                        endGame('g');
                        continue;
                    }
                    if(theMove.second.second == -2){
                        endGame('s');
                        continue;
                    }
                }
                if(cin.eof()){break;}
                cout<<*b<<endl;
                side = !side;
                side ? cout << "Black's turn" << endl : cout << "White's turn" <<endl;
            }
            if(command == "resign"){
                endGame('g');
            }
            if(command == "setup"){
                cout<<"No setup during a game!"<<endl;
            }
        }
        else if(command == "move"){
            cout<<"Game is not initalized yet!"<<endl;
        }
        else if(command == "setup"){
            side = b->init(std::cin, 0);
            setup = 1;
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