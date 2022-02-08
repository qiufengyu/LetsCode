#include "../header.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int sz = s.length();
        for (int i = 0; i < sz; ++i) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[sz];
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().findTheDifference(s, t) << endl;
    return 0;
}