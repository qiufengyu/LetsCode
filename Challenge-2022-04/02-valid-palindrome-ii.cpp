#include "../header.h"

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        if (j == 0 || j == 1) {
            return true;
        }
        while (i < j) {
            if (s[i] != s[j]) {                
                if (i < s.size() - 1 && s[i+1] == s[j]) {
                    if (helper(s, i+1, j)) {
                        return true;
                    }                    
                }
                if (j > 0 && s[j-1] == s[i]) {
                   if (helper(s, i, j-1)) {
                        return true;
                    }                    
                }
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    bool helper(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().validPalindrome(s) << endl;
    return 0;    
}