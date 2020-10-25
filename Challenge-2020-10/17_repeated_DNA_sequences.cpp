#include "../header.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res;
        vector<string> ans;
        if (s.length() < 10) { return ans; }
        set<string> st;
        for (int i = 0; i <= s.length() - 10; i++) {
            string temp = s.substr(i, 10);
            if (st.count(temp) > 0) {
                res.insert(temp);
            } else {
                st.insert(temp);
            }
        }
        
        for (auto& a: res) {
            ans.push_back(a);
        }
        return ans;
    }
};
