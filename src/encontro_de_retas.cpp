
#include <iostream>

bool encontro(int l1.x, int l1.y, int r1.x, int r1.y, int l2.x, int l2.y, int r2.x, int r2.y)
{
 
    // To check if either rectangle is actually a line
    // For example :  l1 ={-1,0}  r1={1,1}  l2={0,-1}
    // r2={0,1}
 
    if (l1.x == r1.x || l1.y == r1.y || l2.x == r2.x
        || l2.y == r2.y) {
        // the line cannot have positive overlap
        return false;
    }
 
    // If one rectangle is on left side of other
    if (l1.x >= r2.x || l2.x >= r1.x)
        return false;
 
    // If one rectangle is above other
    if (r1.y >= l2.y || r2.y >= l1.y)
        return false;
 
    return true;
}