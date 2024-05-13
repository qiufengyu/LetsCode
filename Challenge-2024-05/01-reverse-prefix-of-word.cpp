#include "../header.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto f = word.find_first_of(ch);
        if (f != string::npos) {
            reverse(word.begin(), word.begin() + f + 1);
        }
        return word;
    }
};