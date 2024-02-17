// # Write a function spiral(n), which takes an integer n and returns the 2D coordinates of the spiral after n steps, starting at (0, 0).

// # The spiral itself looks like this:
// # 
// # ```
// # (-2, 3)-----(-1, 3)----( 0, 3)----( 1, 3)----( 2, 3)----( 3, 3)
// #     |                                                       |
// #     |                                                       |
// # (-2, 2)     (-1, 2)----( 0, 2)----( 1, 2)-----( 2, 2)       .
// #     |          |                                 |          .
// #     |          |                                 |          .
// # (-2, 1)     (-1, 1)    ( 0, 1)----( 1, 1)     ( 2, 1)
// #     |          |           |         |           |
// #     |          |           |         |           |
// # (-2, 0)     (-1, 0)    ( 0, 0)    ( 1, 0)     ( 2, 0)
// #     |          |                     |           |
// #     |          |                     |           |
// # (-2,-1)     (-1,-1)----( 0,-1)----( 1,-1)     ( 2,-1)
// #     |                                            |
// #     |                                            |
// # (-2,-2)-----(-1,-2)----( 0,-2)----( 1,-2)-----( 2,-2)
// #

#include <iostream>

using namespace std;

int const directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


pair<int, int> spiral(int const n) {
    int length = 1, lengthCount = 0;
    int dIndex = 0, dIndexCount = 0;
    int step = 0;
    int startX = 0, startY = 0;
    // step = 0 - 1: length = 1
    // step = 2 - 5: length = 2
    // step = 6 - 12, length = 3
    // step = 13 - 21, length = 4
    while (step < n) {
        startX += directions[dIndex][0];
        startY += directions[dIndex][1];
        dIndexCount++;        
        if (dIndexCount >= length) {
            dIndex++;
            dIndex %= 4;
            dIndexCount = 0;            
        }  
        lengthCount++;
        if (lengthCount == 2 * length) {
            length++;
            lengthCount = 0;
        }      
        step++;
    }
    return {startX, startY};

}

int main() {
    int n = 10;
    pair<int, int> result = spiral(n);
    cout <<  "(" << result.first << ", " << result.second << ")" << endl;
}