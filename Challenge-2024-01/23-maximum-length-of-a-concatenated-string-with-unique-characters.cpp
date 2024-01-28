#include "../header.h"

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<string, int>> arrBits;
        int res = 0;
        for (auto const& s: arr) {
            int bits = 0;
            for (char c: s) {
                bits = bits | (1 << (c - 'a'));
            }
            arrBits.push_back({s, bits});
        }
        for (int i = 0; i < arr.size(); i++) {
            dfs(arrBits, 0, i, res);
        }        
        return res;
    }

    int countBits(int n) {
        int b = 0;
        while (n) {
            b++;
            n = n & (n-1);
        }
        return b;
    }

    void dfs(vector<pair<string, int>>& arrBits, int bits, int idx, int& res) {
        if (idx < arrBits.size()) {
            auto current = arrBits[idx];
            string s = current.first;
            int b = current.second;
            int currentBits = countBits(b);
            if (currentBits == s.size()) {
                if ((bits & b) == 0) {
                    res = max(res, countBits(bits | b));
                    for (int i = idx + 1; i < arrBits.size(); i++) {
                        dfs(arrBits, bits | b, i, res);
                    }
                }
            }
        }
    }
};