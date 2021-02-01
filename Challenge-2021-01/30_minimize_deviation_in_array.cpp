#include "../header.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int m = INT_MAX;
        for (auto x: nums) {
            x = x & 1 ? x * 2 : x;
            q.push(x);
            m = min(m, x); 
        }
        int ans = q.top() - m;
        while ((q.top() & 1) == 0) {
            int x = q.top();
            q.pop();
            q.push(x/2);
            m = min(x/2, m);
            ans = min(ans, q.top() - m);
        }
        return ans;
    }
};
