#include "../header.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 1, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : 1 + heights[j];
            }
            res = max(res, maxArea(heights));
        }
        return res;
    }

    int maxArea(vector<int>& h) {
        int area = 0;
        stack<int> st;
        for (int i = 0; i < h.size(); i++) {            
            if (st.empty() || h[st.top()] <= h[i]) {
                st.push(i);
            } else {
                int tp = st.top();
                st.pop();
                int w = st.empty() ? i : i - 1 - st.top();
                area = max(area, h[tp] * w);
                i--;
            }
        }
        return area;
    }
};