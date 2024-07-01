#include "../header.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        vector<vector<int>> mp(n, vector<int>(26, 0));        
        for (int i = 0; i < n; i++) {
            for (auto const& c: words[i]) {
                mp[i][c - 'a'] += 1;
            }          
        }
        for (int i = 0; i < 26; i++) {
            string x = "";
            x += ('a' + i);
            int mn = mp[0][i];
            for (int j = 1; j < n; j++) {
                mn = min(mn, mp[j][i]);
            }
            while (mn) {
                res.push_back(x);
                mn--;
            }
        }        
        return res;
    }
};