#include "../header.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            p[i][i] = true;
            ++res;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i + 1 <= j - 1) {
                        if (p[i+1][j-1]) {
                            p[i][j] = true;
                            ++res;
                        }
                    } else {
                        p[i][j] = true;
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().countSubstrings(s) << endl;
    return 0;
}