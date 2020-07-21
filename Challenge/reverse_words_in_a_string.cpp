#include "header.h"

class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < sz; i++) {
            if (s[i] != ' ') {
                if (start != 0) {
                    s[start++] = ' ';
                }
                int j = i;
                while (j < sz && s[j] != ' ') {
                    s[start++] = s[j++];
                }
                reverse(s.begin() + start - (j - i), s.begin() + start);
                i = j;
            }
        }
        s.resize(start);
        return s;
    }
};

int main() {
    string s {"the sky is blue"};
    cout << Solution().reverseWords(s) << endl;
    return 0;
}