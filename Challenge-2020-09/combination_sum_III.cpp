#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(k, n, 1, res, temp);
        return res;
    }

    void helper(int k, int n, int cur, vector<vector<int>> &res, vector<int>& temp) {
        if (n < 0) return;
        if (n == 0 && temp.size() == k) {
            res.push_back(temp);
        }
        for (int i = cur; i <= 9; i++) {
            temp.push_back(i);
            helper(k, n - i, i + 1, res, temp);
            temp.pop_back();
        }
    }
};

int main() {
    int k, n;
    cin >> k >> n;
    auto res = Solution().combinationSum3(k, n);
    print_vector(res);
    return 0;
}