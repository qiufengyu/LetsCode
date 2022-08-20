#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        int start = 1;
        helper(res, k, n, current, start);
        return res;
    }

    void helper(vector<vector<int>>& res, int k, int n, vector<int>& current, int start) {
        if (current.size() == k && n == 0) {
            res.push_back(current);
        } else if (current.size() < k && n > 0) {
            for (int i = start; i <= 9 && n - i >= 0 ; ++i) {
                current.push_back(i);
                helper(res, k, n - i, current, i + 1);
                current.pop_back();
            }
        }
    }
};

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> res = Solution().combinationSum3(k, n);
    print_vector<int>(res);
    return 0;
}