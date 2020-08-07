#include "../header.h"

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<pair<int, int>, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                auto p = q.front();
                q.pop();
                m[{p.first, level}].push_back(p.second->val);
                if (p.second->left) {
                    q.push({p.first - 1, p.second->left});
                }
                if (p.second->right) {
                    q.push({p.first + 1, p.second->right});
                }
                sz--;
            }
            level++;
        }
        // map is ordered
        map<int, vector<int>> mm;
        for (auto me: m) {
            // sort the second
            sort(me.second.begin(), me.second.end());
            mm[me.first.first].insert(mm[me.first.first].end(), me.second.begin(), me.second.end());
        }
        for (auto entry: mm) {
            res.push_back(entry.second);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    auto res = Solution().verticalTraversal(root);
    print_vector(res);
    return 0;
}