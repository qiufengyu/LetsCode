#include "../header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        stack<char> st;
        int count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (st.empty()) {
                st.push(num[i]);
            } else {
                char x = st.top();
                if (x > num[i]) {
                    while (!st.empty() && st.top() > num[i] && count < k) {
                        st.pop();
                        count++;
                    }
                }
                st.push(num[i]);                
            }
        }
        while (st.size() > num.size() - k) {
            st.pop();
        }
        string res(num.size() - k, 0);
        for (int i = num.size() - k - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        int nonZero = -1;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != '0') {
                nonZero = i;
                break;
            } 
        }
        if (nonZero == -1) {
            return "0";
        }
        string r = res.substr(nonZero);
        return r.size() == 0 ? "0" : r;
    }
};

int main() {
    string num = "100";
    int k = 1;
    cout << Solution().removeKdigits(num, k) << endl;
    return 0;
}