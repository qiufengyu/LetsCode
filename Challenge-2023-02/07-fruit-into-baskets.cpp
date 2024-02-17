#include "../header.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int i = 0, fs = 0, res = 0;
        while (i < fruits.size()) {
            ++m[fruits[i]];
            if (m.size() > 2) {
                --m[fruits[fs]];
                if (m[fruits[fs]] == 0) {
                    m.erase(fruits[fs]);
                }
                ++fs;
            } else {
                res = max(res, i - fs + 1);
            }            
            ++i;
        }
        return res;
    }
};