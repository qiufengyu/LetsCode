#include "../header.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res;
        int i = 0, j = 1;
        while (j < dominoes.size()) {
            if (dominoes[j] == '.') {
                continue;
            }
            int m = j - i - 1;
            if (i > 0) {
                res += dominoes[i];
            }
            if (dominoes[i] == dominoes[j]) {
                res += string(m, dominoes[i]);
            } else if (dominoes[i] == 'L' && dominoes[j] == 'R') {
                res += string(m, '.');
            } else {
                res += (string(m/2, 'R') + string(m%2, '.') + string(m/2, 'L'));
            }
            i = j;
        }
        return res;
    }
};