#include "../header.h"

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            char p = colors[i-1], c = colors[i], n = colors[i+1];
            if (p == 'A' && c == 'A' && n == 'A') {
                a++;
            } else if (p == 'B' && c == 'B' && n == 'B') {
                b++;
            }
        }
        return a > b;
    }
};