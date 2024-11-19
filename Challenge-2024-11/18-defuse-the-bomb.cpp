#include "../header.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> codes(code.begin(), code.end());
        codes.insert(codes.end(), code.begin(), code.end());
        codes.insert(codes.end(), code.begin(), code.end());
        vector<int> res(n, 0);
        for (int i = 0; i < 3*n; i += 3) {
            if (k < 0) {
                for (int j = i / 3 + n + k; j < i / 3 + n; j++) {
                    res[i/3] += codes[j];
                }
            } else {
                for (int j = i / 3 + n + 1; j < i / 3 + n + k + 1; j++) {
                    res[i/3] += codes[j];
                }
            }           
        }
        return res;
    }
};