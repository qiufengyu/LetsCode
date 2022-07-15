#include "../header.h"

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        // trick: sort desc
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int sz = matchsticks.size();
        vector<int> sides(4, 0);
        return helper(matchsticks, sides, 0, sz, sum / 4);
    }

    bool helper(vector<int>& matchsticks, vector<int>& sides, int index, int n, int target) {
        if (index >= n) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }
            int j = i - 1;
            // trick: can skip cases if sides[i] == sides[j] 
            while (j >= 0) {
                if (sides[j] == sides[i]) {
                    break;
                }
                --j;
            }
            if (j >= 0) {
                continue;
            }
            sides[i] += matchsticks[index];
            if (helper(matchsticks, sides, index + 1, n, target)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().makesquare(v) << endl;
    return 0;
}