#include "../header.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> removed;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    removed.insert(i);
                }
            }
        }
        int rest = st.size();
        while (rest) {
            removed.insert(st.top());
            st.pop();
            rest--;
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (removed.count(i) == 0) {
                res.push_back(s[i]);
            }            
        }
        return res;
    }
};