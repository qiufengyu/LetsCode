#include "../header.h"

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long l = 0;
        for (auto c: S) {
            if (isdigit(c)) {
                l *= (int)(c - '0');
            } else {
                l++;
            }
        }
        int sz = S.length() - 1;
        while (sz >= 0) {
            K = K % l;
            if (isalpha(S[sz]) && K == 0) {
                return string(1, S[sz]);
            } else if (isalpha(S[sz])) {
                l--;
            } else {
                l = l / (int)(S[sz] - '0');
            }
            sz--;
        }
        return "";
    }
};
