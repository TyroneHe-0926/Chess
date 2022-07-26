#include <iostream>
#include <string>
#include "gui.h"
#include "cell.h"
#include "textdisplay.h"

#include <chrono>
#include <thread>

void GUI::drawPiece(char type, int j, int i){
    updates++;
    int square = dispsize/9;
    int start = square/2;
    int locx = start+(square*i);
    int locy = start+(square*j);
    Colour outcol = {(char)0, (char)0, (char)0};
    if((i+j)%2 == 0){outcol = light;}
    else{outcol = dark;}
    s.draw_rect(locx, locy, square, square, outcol);
    switch(type){
        case 'P':
            s.draw_img("Pawn", locx, locy);
            break;
        case 'p':
            s.draw_img("Pawn", locx, locy);
            break;
        case 'R':
            s.draw_img("Rook", locx, locy);
            break;
        case 'r':
            s.draw_img("Rook", locx, locy);
            break;
        case 'N':
            s.draw_img("Knight", locx, locy);
            break;
        case 'n':
            s.draw_img("Knight", locx, locy);
            break;
        case 'B':
            s.draw_img("Bishop", locx, locy);
            break;
        case 'b':
            s.draw_img("Bishop", locx, locy);
            break;
        case 'Q':
            s.draw_img("Queen", locx, locy);
            break;
        case 'q':
            s.draw_img("Queen", locx, locy);
            break;
        case 'K':
            s.draw_img("King", locx, locy);
            break;
        case 'k':
            s.draw_img("King", locx, locy);
            break;
    }
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


void GUI::update(TextDisplay* disp){
    updates = 0;
    drawBoard();
    int square = dispsize/9;
    int start = square/2;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            drawPiece(disp->atPos(i, j), i, j);
        }
    }
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
    //255,228,181
};

GUI::~GUI(){}
