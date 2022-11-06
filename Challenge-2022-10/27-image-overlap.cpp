#include "../header.h"

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> da, db;
        int n = img1.size(), res = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) {
                    da.push_back(100 * i + j);
                }
                if (img2[i][j] == 1) {
                    db.push_back(100 * i + j);
                }
            }
        }
        for (int a: da) {
            for (int b: db) {
                count[a - b]++;
            }
        }
        for (auto p: count) {
            res = max(res, p.second);
        }
        return res;
    }
};