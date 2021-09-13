#include "../header.h"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        bool* visited = new bool[n];
        int res = 1;
        memset(visited, 0, n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            int count = 0, j = i;
            while (true) {
                visited[j] = true;
                j = nums[j];
                count++;
                if (j == i) {
                    break;
                }
            }
            res = max(res, count);
        }
        return res;
    }
};