#include "../header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int end = n - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        int e = end;
        while (end >= 0 && s[end] != ' ') {
            end--;
        }
        return e - end;
    }
};