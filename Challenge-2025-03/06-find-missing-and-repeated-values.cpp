#include "../header.h"

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), sum = 0;
        int repeated = -1;
        unordered_set<int> st;
        for (auto const& g: grid) {
            for (int i = 0; i < n; i++) {
                sum += g[i];
                if (st.count(g[i])) {
                    repeated = g[i];
                } else {
                    st.insert(g[i]);
                }
            }
        }
        int s = (1 + n * n) * (n * n) / 2;
        int missing = repeated + s - sum;
        return {repeated, missing};
    }
};