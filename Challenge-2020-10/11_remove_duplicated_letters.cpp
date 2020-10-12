#include "../header.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> m;
        map<char, bool> mb;
        for (auto c: s) {
            ++m[c];
            mb[c] = false;
        }
        stack<char> st;
        for (auto c: s) {
            m[c]--;
            if (mb[c]) {
                continue;
            }
            while (!st.empty() && st.top() > c && m[st.top()] > 0) {
                mb[st.top()] = false;
                st.pop();
            }
            st.push(c);
            mb[c] = true;
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().removeDuplicateLetters(s) << endl;
    return 0;
}