#include "../header.h"

class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1;
        int sz = s.size();
        stack<int> st;
        for (int i = 0; i < sz; ++i) {
            char c = s[i];
            if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            } else if (c >= '0') {
                int temp = 0;
                while (i < sz && s[i] >= '0') {
                    temp = 10 * temp + (s[i] - '0');
                    i++;
                }
                res += sign * temp;
                i--;
            }
        }
        return res;
    }
};