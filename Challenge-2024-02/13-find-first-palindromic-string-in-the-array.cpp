#include "../header.h"

class Solution {
    bool palindrome(string const& w) {
        int n = w.size();
        for (int i = 0; i < n / 2; i++) {
            if (w[i] != w[n-i-1]) {
                return false;
            }
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (auto const& w: words) {
            if (palindrome(w)) {
                return w;
            }
        }
        return "";
    }
};