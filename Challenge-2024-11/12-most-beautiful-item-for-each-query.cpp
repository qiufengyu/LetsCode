#include "../header.h"

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> res(queries.size(), 0);
        vector<int> beauty(items.size(), 0);
        beauty[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            beauty[i] = max(beauty[i-1], items[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            vector<int>&& target = {queries[i], INT_MAX};
            auto it = upper_bound(items.begin(), items.end(), target);
            if (distance(items.begin(), it) > 0) {
               res[i] = beauty[it - items.begin() - 1];
            }
        }
        return res;
    }
};