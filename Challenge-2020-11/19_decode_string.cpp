#include "../header.h"

class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != ']') {
                st.push(c);
            } else {
                string temp {""};
                while (!st.empty() && st.top() != '[') {
                    temp.insert(temp.begin(), st.top());
                    st.pop();
                }
                st.pop(); // pop '['
                int count = 0;
                string countString = {""};
                while (!st.empty()) {
                    char d = st.top();
                    if (d >= '0' && d <= '9') {
                        countString.insert(countString.begin(), d);
                        st.pop();
                    } else {
                        break;
                    }
                }
                count = stoi(countString);
                while (count > 0) {
                    count--;
                    for (auto x: temp) {
                        st.push(x);
                    }
                }
            }
        }
        while (!st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};