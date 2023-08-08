#include "../header.h"

struct Item {
    int start;
    int end;
    Item(): start{0}, end{0} {}
    Item(int s, int e): start{s}, end{e} {}
    bool operator==(const Item &p) const {
        return start == p.start && end == p.end;
    }
};

struct hashItem {
    size_t operator()(Item const& i) const noexcept {
        size_t h1 = hash<int>{}(i.start);
        size_t h2 = hash<int>{}(i.end);
        return h1 ^ (h2 << 1);
    }
};

class Solution {    
    unordered_map<Item, vector<TreeNode*>, hashItem> dp;
public:
    vector<TreeNode*> generateTrees(int n) {        
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        Item key = Item{start, end};
        if (start > end) {
            dp[key] = {nullptr};
            return {nullptr};
        }        
        if (dp.count(key) != 0) {
            return dp[key];
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto& ln: left) {
                for (auto& rn: right) {
                    TreeNode *in = new TreeNode(i);
                    in->left = ln;
                    in->right = rn;
                    res.push_back(in);
                }
            }
        }
        dp[key] = res;
        return res;
    }
};