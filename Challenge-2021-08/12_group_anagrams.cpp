#include "../header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto const& s: strs) {
            string ss{s};
            sort(ss.begin(), ss.end());            
            m[ss].push_back(s);
        }
        vector<vector<string>> res;
        for (auto const& [k, v]: m) {
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<string> strs = stringToStringVector(s);
    auto res = Solution().groupAnagrams(strs);
    print_vector<string>(res);
    return 0;
}
