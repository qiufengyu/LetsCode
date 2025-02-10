#include "../header.h"

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        string res(st.size(), '0');
        int index = st.size() - 1;
        while(!st.empty()) {
            res[index] = st.top();
            st.pop();
            index--;
        }
        return res;
    }
};