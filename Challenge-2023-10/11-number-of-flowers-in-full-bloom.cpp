#include "../header.h"

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for (auto const& flower: flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        for (int p: people) {
            int s = upper_bound(start.begin(), start.end(), p) - start.begin();
            int e = lower_bound(end.begin(), end.end(), p) - end.begin();
            res.push_back(max(s - e, 0));
        }
        return res;        
    }
};