#include "../header.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]-'a'] = i;
        }
        vector<bool> visited(26, false);
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            int ci = s[i] - 'a';
            if (visited[ci]) {
                continue;
            }
            while (!st.empty() && st.top() > ci && i < lastIndex[st.top()]) {
                int tp = st.top();
                st.pop();
                visited[tp] = false;
            }
            st.push(ci);
            visited[ci] = true;
        }
        string res;
        while (!st.empty()) {
            res.push_back(('a' + st.top()));
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};