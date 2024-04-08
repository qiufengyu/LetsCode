#include "../header.h"

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        int const d = abs('a' - 'A');
        if (n <= 1) {
            return s;
        }
        stack<char> st;
        st.push(s[0]);        
        for (int i = 1; i < n; i++) {
            if (!st.empty() && abs(st.top()-s[i]) == d) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        int sz = st.size();
        string res(sz, 0);
        while (sz > 0) {
            res[sz-1] = st.top();
            st.pop();
            sz--;
        }
        return res;
    }
};