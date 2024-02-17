#include "../header.h"

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        unordered_map<int, vector<int>> m;
        m[0] = {4,6};
        m[1] = {6,8};
        m[2] = {7,9};
        m[3] = {4,8};
        m[4] = {0,3,9};
        m[6] = {0,1,7};
        m[7] = {2,6};
        m[8] = {1,3};
        m[9] = {2,4};
        vector<long long> counts1(10, 1LL), counts2(10, 0LL);
        counts1[5] = 0;
        int const M = 1000000007;
        long long res = 0;
        for (int l = 1; l < n; l++) {
            for (auto const& p: m) {
                counts2[p.first] = 0;
                for (auto const& x: p.second) {
                    counts2[p.first] = (counts2[p.first] + counts1[x]) % M;
                }                
            }
            swap(counts1, counts2);
        }
        for (int i = 0; i < 10; i++) {
            res = (res + counts1[i]) % M;
        }
        return (int)res;        
    }
};