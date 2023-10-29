#include "../header.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int const M = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> m;
        for (int i = 0; i < arr.size(); i++) {
            int current = arr[i];
            m[current] = 1;
            for (int j = 0; j < i && arr[j] <= sqrt(current); j++) {
                int q = current / arr[j];
                if (q * arr[j] == current && m.count(q)) {
                    // if a == arr[j], left and right are identical tree
                    m[current] += ((m[arr[j]] * m[q]) * (1 + (arr[j] != q)));
                    m[current] %= M;                    
                }
            }
        }
        int res = 0;
        for (auto const& p: m) {
            res += p.second;
            res %= M;
        }
        return res;
    }
};