#include "../header.h"

inline int getLine(const string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ++res;
        }
    }
    return res;
}

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        if (n == 1) {
            return 0;
        }
        int res = 0;
        vector<int> rows(n, 0);
        for (int i = 0; i < n; i++) {
            rows[i] = getLine(bank[i]);
        }
        int idx = 0, prev = -1;
        while (idx < n) {
            while (idx < n && rows[idx] == 0) {
                idx++;
            }
            if (idx < n) {
                if (prev != -1) {
                    res += (prev * rows[idx]);
                }
                prev = rows[idx];                
            }            
            idx++;
        }
        return res;
    }
};