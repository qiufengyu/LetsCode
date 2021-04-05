#include "../header.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.length(), res = 0;
        int start = 0;
        stack<int> st;
        for (int i = 0; i < sz; ++i) {
          if (s[i] == '(') {
            st.push(i);
          } else {
            if (st.empty()) {
              start = i + 1;
            } else {
              st.pop();
              int temp = st.empty() ? i - start + 1 : i - st.top();
              res = max(res, temp);
            }
          }
        }
        return res;
    }
};