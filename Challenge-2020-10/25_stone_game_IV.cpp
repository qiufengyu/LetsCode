#include "../header.h"

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> cache(n+1, 0);
        return win(n, cache) > 0;
    }

    int win(int n, vector<int>& cache) {
        if (n == 0) {
            return -1;
        }
        if (cache[n] != 0) {
            return cache[n];
        }
        for (int i = sqrt(n); i >= 1; i--) {
            if (win(n - i * i, cache) < 0) {
                cache[n] = 1;
                return 1;
            }
        }
        cache[n] = -1;
        return -1;
    }
};