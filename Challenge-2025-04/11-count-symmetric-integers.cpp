#include "../header.h"

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            string si = to_string(i);
            if ((si.size()) % 2 == 1) {
                if (i >= 10) {
                    i = i * 10 - 1;
                }                
            } else {
                int l = 0, r = 0;
                for (int j = 0; j < si.size() / 2; j++) {
                    l += si[j];
                    r += si[si.size() - 1 - j];
                }
                if (l == r) {
                    res += 1;
                }
            }
        }
        return res;
    }
};