#include "../header.h"

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      int sz = s.size();
      for (int i = 0; i < sz; i++) {
        char c = s[i];
        if (c == '[' || c == '{' || c == '(') {
          st.push(c);
        } else {
          if (st.empty()) {
            return false;
          } else {
            char x = st.top();
            if (c == ')' && x == '(') {
              st.pop();
            } else if (c == ']' && x == '[') {
              st.pop();
            } else if (c == '}' && x == '{') {
              st.pop();
            } else {
              return false;
            }
          }
        }
      }
      return st.empty();        
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().isValid(s) << endl;
  return 0;
}