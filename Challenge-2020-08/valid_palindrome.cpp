#include "../header.h"

class Solution {
public:
    bool isPalindrome(string s) {
        string f = "";
        for (auto x: s) {
            if ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')) {
                f.push_back(x);
            } else if (x >= 'A' && x <= 'Z') {
                f.push_back(x + 32);
            }
        }
        // cout << f << endl;
        int fl = f.length();
        for (int i = 0; i < fl / 2; i++) {
            if (f[i] != f[fl-1-i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin, s);
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}