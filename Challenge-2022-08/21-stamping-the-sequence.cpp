#include "../header.h"

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int ls = stamp.size(), lt = target.size();
        string temp(lt, '?');
        vector<int> res;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < lt - ls + 1; ++i) {
                changed |= check(i, ls, stamp, target, res);
            }
        }
        if (target == temp) {
            reverse(res.begin(), res.end());
            return res;
        }
        return {};
    }

    bool check(int index, int ls, string const stamp, string target, vector<int>& res) {
        bool changed = false;
        for (int i = 0; i < ls; ++i) {
            if (target[index + i] == '?') {
                continue;
            }
            if (target[index + i] != stamp[i]) {
                return false;
            }
            changed = true;
        }
        if (changed) {
            for (int i = 0; i < ls; ++i) {
                target[index + i] = '?';
            }
            res.push_back(index);
        }
        return changed;
    }
};