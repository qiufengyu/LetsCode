#include "../header.h"

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> stRepeat;
        int repeat = 0;
        string temp = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                st.push(temp);
                temp = "";
                stRepeat.push(repeat);
                repeat = 0;
            } else if (s[i] >= '0' && s[i] <= '9') {
                repeat = repeat * 10 + s[i] - '0';
            } else if (s[i] == ']') {
                int rt = stRepeat.top();
                stRepeat.pop();
                string rtemp = st.top();
                st.pop();
                while (rt > 0) {
                    --rt;
                    rtemp.append(temp);
                }                
                temp = rtemp;             
            } else { // s[i] >= 'a' && s[i] <= 'z'
                temp.push_back(s[i]);
            }
        }
        return temp;
    }
};

int main() {
    string s;
    cin >> s;
    string res = Solution().decodeString(s);
    cout << res << endl;
    return 0;
}