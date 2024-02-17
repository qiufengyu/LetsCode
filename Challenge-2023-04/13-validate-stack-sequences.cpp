#include "../header.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int pushIndex = 0, popIndex = 0;
        for (int i = 0; i < n; ++i) {
            int pp = pushed[i];
            if (pp != popped[popIndex]) {
                st.push(pp);
            } else {
                popIndex++;
                while (!st.empty() && popIndex < n) {
                    if (st.top() == popped[popIndex]) {
                        popIndex++;
                        st.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        while (!st.empty() && popIndex < n) {
            if (st.top() != popped[popIndex]) {
                return false;
            }
            st.pop();
            popIndex++;
        }
        return st.empty() && popIndex == n;
    }
};