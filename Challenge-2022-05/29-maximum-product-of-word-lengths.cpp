#include "../header.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((hash(words[i]) & hash(words[j])) == 0) {
                    res = max(res, int(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }

    int hash(const string& s) {
        int h = 0;
        for (char const& c: s) {
            h = h | (1 << (int(c - 'a')));
        }
        return h;
    }    
};