#include "../header.h"

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char t = st.top();
                if (t == s[i]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().removeDuplicates(s) << endl;
    return 0;
}