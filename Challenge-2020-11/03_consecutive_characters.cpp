#include "../header.h"

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int count = 1;
        char c = s[0]; // s.length >= 1
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
                ans = max(ans, count);
            } else {
                count = 1;
            }
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maxPower(s) << endl;
    return 0;
}