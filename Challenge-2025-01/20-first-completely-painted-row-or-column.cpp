#include "../header.h"

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        int m = mat.size(), n = mat[0].size();
        int idx = arr.size() - 1;
        for (int i = 0; i < m; i++) {
            int mx = 0;
            for (int j = 0; j < n; j++) {
                mx = max(mx, mp[mat[i][j]]);
            }
            if (mx <= idx) {
                idx = mx;
            }
        }
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, mp[mat[i][j]]);
            }
            if (mx <= idx) {
                idx = mx;
            }
        }
        return idx;
    }
};