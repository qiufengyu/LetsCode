#include "../header.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto const& t: tokens) {
            if (t == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            } else if (t == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (t == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            } else if (t == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                int n = std::stoi(t);
                st.push(n);
            }
        }
        return st.top();
    }
};