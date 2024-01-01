#include "../header.h"

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int i = 0, j = 0, n = colors.size();
        while (i < n && j < n) {
            int ttl = 0, mx = 0;
            while (j < n && colors[i] == colors[j]) {
                ttl += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            res += ttl - mx;
            i = j;
        }
        return res;
    }
};