#include "../header.h"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int score = 0, res = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                ++score;
                ++left;
                res = max(res, score);
            } else if (score > 0) {
                power += tokens[right];
                --right;
                --score;
            } else {
                break;
            }
        }
        return res;
    }
};