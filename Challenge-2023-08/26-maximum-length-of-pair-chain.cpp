#include "../header.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        int current = INT_MIN, res = 0;
        for (auto const& p: pairs) {
            if (p[0] > current) {
                res++;
                current = p[1];
            }
        }
        return res;
    }
};