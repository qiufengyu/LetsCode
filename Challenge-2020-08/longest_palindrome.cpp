#include "../header.h"

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int res = 0;
        for (auto c: s) {
            m[c]++;
        }
        bool hasSingle = false;
        for (auto p: m) {
            if (p.second % 2 != 0) {
                hasSingle = true;
            }
            res += ((p.second / 2) * 2);
        }
        if (hasSingle) {
            res++;
        }
        return res;        
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}