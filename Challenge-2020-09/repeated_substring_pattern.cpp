#include "../header.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.size();
        for (int i = l / 2; i > 0; i--) {
            if (l % i == 0) {
                string temp = "";
                for (int j = 0; j < l / i; j++) {
                    temp += s.substr(0, i);
                }
                if (temp.compare(s) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().repeatedSubstringPattern(s) << endl;
    return 0;
}