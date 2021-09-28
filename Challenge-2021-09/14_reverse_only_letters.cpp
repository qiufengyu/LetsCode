#include "../header.h"

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int sz = s.size();
        int i = 0, j = sz - 1;
        while (i < j) {
            while (!isalpha(s[i]) && i < j) {
                ++i;
            }
            while (!isalpha(s[j]) && i < j) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().reverseOnlyLetters(s) << endl;
    return 0;
}