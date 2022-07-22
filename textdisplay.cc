#include "textdisplay.h"

TextDisplay::TextDisplay(){
    
}

std::ostream &operator<<(std::ostream& out, const TextDisplay& ptd){
    for(auto i: ptd.display){
        for(auto j: i){
            out << j;
        }
        out << std::endl;
    }
    return out;
}