#include "../header.h"

class Solution {
public:
    string countAndSay(int n) {
        return countAndSay(n - 1, "1");
    }

    string countAndSay(int n, string s)  {
        if (n == 0) {
            return s;
        }
        string ss = count(s);
        return countAndSay(n-1, ss);
    }

    string count(string const& s) {
        int n = s.size();
        int i = 0;
        string res = "";
        int cnt = 1;
        while (i < n - 1) {
            if (s[i] == s[i+1]) {
                ++cnt;
            } else {
                res += (to_string(cnt) + s[i]);
                cnt = 1;
            }
            ++i;
        }
        res += (to_string(cnt) + s[n-1]);
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().count(s) << endl;
    return 0;
}