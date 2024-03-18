#include "../header.h"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, res = 0;
        int i = 0, j = tokens.size() - 1;
        while (power >= 0 && i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i];
                score++;
                res = max(res, score);                
                cout << "power -= " << tokens[i] << ", power = " << power << ", score = " << score << endl;
                i++;
            } else {
                if (score > 0) {
                    score--;
                    power += tokens[j];
                    cout << "power += " << tokens[j] << ", power = " << power << ", score = " << score << endl;
                    j--;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> tokens{33,41,10,91,47,84,98,34,48,70};
    int power = 43;
    cout << Solution().bagOfTokensScore(tokens, power) << endl;
    return 0;
}