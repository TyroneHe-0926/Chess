#include "gui.h"
#include "cell.h"
#include <iostream>
#include <string>


#include <chrono>
#include <thread>

void GUI::notify(Cell&c){
    if(updates == 0){
        drawBoard();
    }
    updates++;
    int square = dispsize/9;
    int start = square/2;
    int i = (int) c.getCoords().first;
    --i;
    int j = c.getCoords().second;
    --j;
    int locx = start+(square*i);
    int locy = start+(square*j);
    Colour outcol = {(char)0, (char)0, (char)0};
    if((i+j)%2 == 0){outcol = light;}
    else{outcol = dark;}
    s.draw_rect(locx, locy, square, square, outcol);
    if(c.getType().first != PieceType::Empty){
        switch(c.getType().first){
            case PieceType::Pawn:
                s.draw_img("Pawn", locx, locy);
                break;
            case PieceType::Rook:
                s.draw_img("Rook", locx, locy);
                break;
            case PieceType::Knight:
                s.draw_img("Knight", locx, locy);
                break;
            case PieceType::Bishop:
                s.draw_img("Bishop", locx, locy);
                break;
            case PieceType::Queen:
                s.draw_img("Queen", locx, locy);
                break;
            case PieceType::King:
                s.draw_img("King", locx, locy);
                break;
        }
        if(c.getType().second == true){outcol = {(char)255,(char)255,(char)255};}
        else{outcol = {(char)0, (char)0, (char)0};}
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void GUI::drawBoard(){
    s.draw_rect(0,0, dispsize, dispsize, dark);
    int square = dispsize/9;
    int start = square/2;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                s.draw_rect(start+(square*i), start+(square*j), 
                    square, square, light);
            }
        }
    }
}


void GUI::update(){
    updates = 0;
    s.update();
}

GUI::GUI(): s{Screen(dispsize,dispsize,"Chess")}, updates{0}{
    s.add_img("Pawn", "images/BPawn.png");
    s.add_img("Rook", "images/rook.png");
    s.add_img("Knight", "images/knight.png");
    s.add_img("Bishop", "images/bishop.png");
    s.add_img("Queen", "images/queen.png");
    s.add_img("King", "images/king.png");
    drawBoard();
    s.update();
    //255,228,181
};

