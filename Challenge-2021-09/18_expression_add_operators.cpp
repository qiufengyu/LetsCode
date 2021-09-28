#include "../header.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, "", 0, 0, res);
        return res;
    }

    void dfs(string const& num, int const target, int pos, string const& exp, long prev, long current, vector<string>& res) {
        if (pos == num.size()) {
            if (current == target) {
                res.push_back(exp);
                return;
            }
        }
        for (int i = 1; i <= num.size() - pos; ++i) {
            string temp = num.substr(pos, i);
            if (temp[0] == '0' && temp.size() > 1) {
                break;
            }
            long n = stol(temp);
            if (n > INT_MAX) {
                break;
            }
            if (pos == 0) {
                dfs(num, target, i, temp, n, n, res);
                continue;
            }
            dfs(num, target, pos + i, exp + '+' + temp, n, current + n, res);
            dfs(num, target, pos + i, exp + '-' + temp, -n, current - n, res);
            dfs(num, target, pos + i, exp + '*' + temp, prev * n, current - prev + n * prev, res);
        }
    }
};