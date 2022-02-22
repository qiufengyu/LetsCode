#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> s(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        int currentSum = 0;
        helper(s, current, currentSum, target, res);
        return res;
    }

    void helper(set<int>& s, vector<int>& current, int currentSum, int const target, vector<vector<int>>& res) {
        if (currentSum < target) {
            for (int const& n: s) {
                if (current.size() > 0 && current.back() > n) {
                    continue;
                }
                currentSum += n;
                current.push_back(n);
                if (currentSum == target) {
                    res.push_back(current);
                } else if (currentSum < target) {
                    helper(s, current, currentSum, target, res);
                }
                currentSum -= n;
                current.pop_back();
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    int target;
    cin >> target;
    vector<int> candidates = stringToIntegerVector(s);
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    print_vector<int>(res);
    return 0;
}