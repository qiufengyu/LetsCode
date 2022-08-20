#include "../header.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int l = words[0].size();
        int t = n * l;
        if (s.size() < t) {
            return {};
        }
        vector<int> res;
        for (int i = 0; i < s.size() - t + 1; ++i) {
            unordered_map<string, int> m;
            for (int j = 0; j < words.size(); ++j) {
                m[words[j]]++;
            }
            int k;
            for (k = 0; k < n; ++k) {
                string temp = s.substr(i + k * l, l);
                if (m.count(temp) == 0 || m[temp] <= 0) {
                    break;
                } else {                    
                    --m[temp];
                }
            }
            if (k == n) {
                res.push_back(i);
            }
        }
        return res;
    }
};