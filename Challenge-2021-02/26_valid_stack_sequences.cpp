#include "../header.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int len = pushed.size();
        int iPop = 0, iPush = 0;
        while (iPop < len) {
            if (st.size() > 0 && st.top() == popped[iPop]) {
                ++iPop;
                st.pop();
            } else {
                if (iPush >= len) {
                    return false;
                }
                st.push(pushed[iPush]);
                ++iPush;
            }
        }
        return st.empty() && iPush >= len;
    }
};
