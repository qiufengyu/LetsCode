#include "../header.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, current;
        helper(s, res, current, 0, 1);
        return res;
    }

    void helper(const string& s, vector<string>& res, vector<string>& current, int start, int end) {
        // cout << "helper: start = " << start << ", end = " << end << endl;
        // print_vector<string>(current);
        if (current.size() == 4 && start == s.size()) {
            string ss = "";
            for (auto const& a: current) {
                ss += a;
                ss.push_back('.');
            }
            ss.pop_back();
            res.push_back(ss);
        } else if (current.size() <= 3 && end <= s.size()) {
            while (end - start <= 3) {
                string t = s.substr(start, end - start);
                // cout << start << " - " << end << ": " << t << endl;
                if (((stoi(t) > 0 && t[0] != '0') && stoi(t) <= 255) || t == "0") {
                    current.push_back(t);                    
                    helper(s, res, current, end, end + 1);                    
                    current.pop_back();
                }
                ++end;
            }
        }        
    }
};

int main() {
    string s;
    cin >> s;
    vector<string> res = Solution().restoreIpAddresses(s);
    print_vector<string>(res);
    return 0;
}