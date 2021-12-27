#include "../header.h"

// https://en.cppreference.com/w/cpp/string/basic_string/replace
std::size_t replace_all(std::string& inout, std::string_view what, std::string_view with)
{
    std::size_t count{};
    for (std::string::size_type pos{};
         inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length(), ++count) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';
        replace_all(s, " ", "");
        s.push_back('+');
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            if (op == '+') {
                st.push(num);
            } else if (op == '-') {
                st.push(-num);
            } else {
                int temp;
                if (op == '*') {
                    temp = st.top() * num;
                } else {
                    temp = st.top() / num;
                }
                st.pop();
                st.push(temp);
            }
            num = 0;
            op = c;  
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};