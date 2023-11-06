#include "../header.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int current = 1;
        for (int i = 0; i < target.size(); i++) {
            res.push_back("Push");
            while (current <= n && target[i] != current) {
                res.push_back("Pop");
                ++current;
                res.push_back("Push");
            }
            ++current;
        }
        return res;
    }
};