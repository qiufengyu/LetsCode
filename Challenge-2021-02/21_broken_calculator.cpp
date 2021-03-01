#include "../header.h"

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (X < Y) {
            if (Y % 2 == 0) {
                Y = Y / 2;
            } else {
                Y = Y + 1;
            }
            ++res;
        }
        return res + (X - Y);
    }
};
