#include "../header.h"

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length = 0;
        int i = 0;
        string res = "";
        while (length < k) {
            if (s[i] >= '1' && s[i] <= '9') {
                length *= (s[i] - '0');
            } else {
                length++;
            }
            i++;
        }
        for (int j = i - 1; j>= 0; j--) {
            if (s[j] >= '1' && s[j] <= '9') {
                length /= (s[j] - '0');
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    res.push_back(s[j]);
                    return res;
                }
                length--;
            }
        }
        return "";
    }
};