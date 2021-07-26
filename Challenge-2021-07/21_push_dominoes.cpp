#include "../header.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        size_t sz = dominoes.size();
        vector<int> f(sz, 0);
        int force = 0;
        for (int i = 0; i < sz; ++i) {
            if (dominoes[i] == 'R') {
                force = sz;
            } else if (dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            f[i] += force;
        }
        force = 0;
        for (int i = sz - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                force = sz;
            } else if (dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            f[i] -= force;
        }
        for (int i = 0; i < sz; ++i) {
            if (f[i] > 0) {
                dominoes[i] = 'R';
            } else if (f[i] < 0) {
                dominoes[i] = 'L';
            } else {
                dominoes[i] = '.';
            }
        }
        return dominoes;
    }
};