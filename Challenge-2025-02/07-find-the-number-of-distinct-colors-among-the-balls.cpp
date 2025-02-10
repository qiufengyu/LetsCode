#include "../header.h"

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls, colors;
        vector<int> res(queries.size(), 0);
        int count = 0;
        for (int i = 0; i < queries.size(); i++) {
            int b = queries[i][0], c = queries[i][1];
            if (balls.count(b) == 0) {
                colors[c]++;
                if (colors[c] == 1) {
                    count++;
                }
                
            } else {
                colors[balls[b]]--;
                if (colors[balls[b]] == 0) {
                    count--;
                }
                colors[c]++;
                if (colors[c] == 1) {
                    count++;
                }
            }
            balls[b] = c;
            res[i] = count;
        }
        return res;
    }
};