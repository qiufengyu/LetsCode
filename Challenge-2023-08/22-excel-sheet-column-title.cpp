#include "../header.h"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        int r;
        while (columnNumber > 0) {
            columnNumber--;
            r = columnNumber % 26;
            columnNumber /= 26;
            res.push_back('A' + r);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};