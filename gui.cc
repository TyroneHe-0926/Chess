#include <iostream>
#include <string>
#include "gui.h"
#include "cell.h"
#include "textdisplay.h"

void GUI::drawPiece(char type, int j, int i){
    updates++;
    int square = dispsize/9;
    int start = square/2;
    int locx = start+(square*i);
    int locy = start+(square*j);
    Colour outcol = {(char)0, (char)0, (char)0};
    if((i+j)%2 == 0){outcol = light;}
    else{outcol = dark;}
    s->draw_rect(locx, locy, square, square, outcol);
    switch(type){
        case 'P':
            s->draw_img("WPawn", locx, locy);
            break;
        case 'p':
            s->draw_img("BPawn", locx, locy);
            break;
        case 'R':
            s->draw_img("WRook", locx, locy);
            break;
        case 'r':
            s->draw_img("BRook", locx, locy);
            break;
        case 'N':
            s->draw_img("WKnight", locx, locy);
            break;
        case 'n':
            s->draw_img("BKnight", locx, locy);
            break;
        case 'B':
            s->draw_img("WBishop", locx, locy);
            break;
        case 'b':
            s->draw_img("BBishop", locx, locy);
            break;
        case 'Q':
            s->draw_img("WQueen", locx, locy);
            break;
        case 'q':
            s->draw_img("BQueen", locx, locy);
            break;
        case 'K':
            s->draw_img("WKing", locx, locy);
            break;
        case 'k':
            s->draw_img("BKing", locx, locy);
            break;
    }
}

void GUI::drawBoard(){
    s->draw_rect(0,0, dispsize, dispsize, dark);
    int square = dispsize/9;
    int start = square/2;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                s->draw_rect(start+(square*i), start+(square*j), 
                    square, square, light);
            }
        }
    }
    Colour brown = {(char) 64, (char)22, (char)20};
    for(char i = 'a'; i < 'i'; i++){
        std::string output;
        output+=i;
        int to = square * ((i-'a')+1);
        s->draw_string(output, to-8, 667, brown);
    }
    for(int i = 1; i < 9; i++){
        std::string output = std::to_string(i);
        int to = square * (9-i);
        s->draw_string(output, 12,to-15, brown);
    }
}


void GUI::update(TextDisplay* disp){
    updates = 0;
    drawBoard();
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            drawPiece(disp->atPos(i, j), i, j);
        }
    }
    s->update();
}

GUI::GUI(): s{new Screen(dispsize,dispsize,"Chess")}, updates{0}{
    s->add_img("BPawn", "images/BPawn.png");
    s->add_img("BRook", "images/BRook.png");
    s->add_img("BKnight", "images/BKnight.png");
    s->add_img("BBishop", "images/BBishop.png");
    s->add_img("BQueen", "images/BQueen.png");
    s->add_img("BKing", "images/BKing.png");
    s->add_img("WPawn", "images/WPawn.png");
    s->add_img("WRook", "images/WRook.png");
    s->add_img("WKnight", "images/WKnight.png");
    s->add_img("WBishop", "images/WBishop.png");
    s->add_img("WQueen", "images/WQueen.png");
    s->add_img("WKing", "images/WKing.png");
    drawBoard();
    //255,228,181
};

GUI::~GUI(){
    delete s;
}
