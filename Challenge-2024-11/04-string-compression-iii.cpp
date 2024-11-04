#include "../header.h"

class Solution {
public:
    string compressedString(string word) {
        string res;
        char x = word[0];
        int count = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] != x) {
                while (count >= 10) {
                    res.push_back('9');
                    res.push_back(x);
                    count -= 9;
                }
                if (count > 0) {
                    res.push_back('0' + count);
                    res.push_back(x);
                }
                x = word[i];
                count = 1;
            } else {
                count++;
            }
        }
        while (count >= 10) {
            res.push_back('9');
            res.push_back(x);
            count -= 9;
        }
        if (count > 0) {
            res.push_back('0' + count);
            res.push_back(x);
        }
        return res;
    }
};