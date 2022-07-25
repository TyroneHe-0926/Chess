#include "types.h"

locationx charToX(char src){
    locationx ret;
    switch(src){
        case 'A':
            ret = A;
            break;
        case 'B':
            ret = B;
            break;
        case 'C':
            ret = C;
            break;
        case 'D':
            ret = D;
            break;
        case 'E':
            ret = E;
            break;
        case 'F':
            ret = F;
            break;
        case 'G':
            ret = G;
            break;
        case 'H':
            ret = H;
            break;
    }
    return ret;
}