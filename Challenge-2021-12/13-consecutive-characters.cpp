#include "../header.h"

class Solution {
public:
    int maxPower(string s) {
        // 1 <= s.length <= 500
        int count = 1, res = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == s[i]) {
                ++count;
                res = max(count, res);
            } else {
                count = 1;
            }
        }
        return max(res, count);
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maxPower(s) << endl;
    return 0;
}