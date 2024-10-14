#include "../header.h"

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        int rank = 1;
        for (auto const& p: mp) {
            for (int i = 0; i < p.second.size(); i++) {
                res[p.second[i]] = rank;
            }
            rank++;
        }
        return res;
    }
};