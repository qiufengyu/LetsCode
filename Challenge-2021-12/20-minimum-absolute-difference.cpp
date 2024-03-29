#include "../header.h"

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minAbs = arr[1] - arr[0], diff = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            diff = arr[i+1] - arr[i];
            if (diff < minAbs) {
                minAbs = diff;
            }
        }
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i+1] - arr[i] == minAbs) {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};