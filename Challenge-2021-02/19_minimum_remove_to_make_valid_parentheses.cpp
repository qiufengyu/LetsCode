#include "../header.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
      set<int> toBeRemoved;
      stack<int> st;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
          st.push(i);
        } else if (s[i] == ')') {
          if (st.size() == 0) {
            toBeRemoved.insert(i);
          } else {
            st.pop();
          }
        }
      }
      while (st.size() > 0) {
        toBeRemoved.insert(st.top());
        st.pop();
      }
      string res;
      for (int i = 0; i < s.size(); i++) {
        if (!toBeRemoved.count(i)) {
          res.push_back(s[i]);
        }
      }
      return res;
    }
};

int main() {
  string s;
  cin >> s;
  cout << Solution().minRemoveToMakeValid(s) << endl;
  return 0;
}
