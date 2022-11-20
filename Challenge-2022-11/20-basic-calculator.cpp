#include "../header.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c >= '0' && c <= '9') {
                int val = 0;
                while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
                    val = val * 10 + (s[i] - '0');
                    ++i;
                }
                res += (sign * val);
                --i; // i go to the last non-digit char
            }
        }
        return res;
    }
};