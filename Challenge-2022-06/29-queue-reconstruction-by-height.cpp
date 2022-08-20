#include "../header.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] > b[0]) {
                return true;
            } else if (a[0] < b[0]) {
                return false;
            } else {
                return a[1] < b[1];
            }
        });
        vector<vector<int>> res;
        for (auto const& p: people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;        
    }
};