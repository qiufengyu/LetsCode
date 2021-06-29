#include "../header.h"

class FenwickTree {
private:
    vector<int> _sums;
    int lowbit(int x) {
        return x & (-x);
    }
public:
    FenwickTree(int n): _sums(n + 1, 0) {}

    void update(int i, int delta) {
        while (i < _sums.size()) {
            _sums[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += _sums[i];
            i -= lowbit(i);
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        for (auto const& num: sorted) {
            ranks[num] = ++rank;
        }
        vector<int> ans;
        FenwickTree tree(ranks.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};