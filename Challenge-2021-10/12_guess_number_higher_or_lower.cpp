 #include "../header.h"

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        int g = l + (r - l) / 2;
        while (l <= r) {
            g = l + (r - l) / 2;
            int x = guess(g);
            if (x == 0) {
                return g;
            } else if (x == 1) {
                l = g + 1;
            } else {
                r = g - 1;
            }
        }
        return g;
    }
};