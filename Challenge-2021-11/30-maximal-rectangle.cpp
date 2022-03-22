#include "../header.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        vector<int> height(n, 0);
        for (int i = 0; i < m; ++i) {
            height.resize(n);
            for (int j = 0; j < n; ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }

    int largestRectangleArea(vector<int>& height) {
        int area = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] <= height[i]) {
                st.push(i);
            } else {
                int t = st.top();
                st.pop();
                area = max(area, height[t] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }
        }
        return area;
    }
};