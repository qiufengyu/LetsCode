#include "../header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, minHeight = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
            } else {
                int t = s.top();
                s.pop();
                int width = s.empty() ? i : i - 1 - s.top();
                res = max(res, heights[t] * width);
                i--;
            }
        }
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            int width = s.empty() ? heights.size(): heights.size() - s.top() - 1;
            res = max(res, heights[t] * width);
        }
        return res;
    }
};