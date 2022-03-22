#include "../header.h"

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, res = 0;
        for (int i = 31; i >= 0; --i) {
            mask = mask | (1 << i);
            set<int> s;
            for (int num: nums) {
                int l = mask & num;
                s.insert(l);
            }
            int greedy = res | (1 << i);
            for (int l: s) {
                if (s.count(l ^ greedy)) {
                    res = greedy;
                    break; 
                }
            }
        }
        return res;
    }
};