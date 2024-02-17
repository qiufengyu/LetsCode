#include "../header.h"

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> m;
        tree2Graph(root, m);
        unordered_set<int> s;
        queue<int> q;
        q.push(start);
        int res = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz) {
                int tp = q.front();
                q.pop();
                s.insert(tp);
                auto adjs = m[tp];
                for (int adj: adjs) {
                    if (s.count(adj) == 0) {
                        q.push(adj);
                    }
                }
                --sz;
            }
            ++res;
        }
        return res;
    }

    void tree2Graph(TreeNode* root, unordered_map<int, vector<int>>& m) {
        if (root) {
            int v = root->val;
            if (root->left) {
                int l = root->left->val;
                m[v].push_back(l);
                m[l].push_back(v);
                tree2Graph(root->left, m);
            }
            if (root->right) {
                int r = root->right->val;
                m[v].push_back(r);
                m[r].push_back(v);
                tree2Graph(root->right, m);
            }
        }
    }
};

int main() {
    string tree = "[1,5,3,null,4,10,6,9,2]";
    TreeNode* root = stringToTreeNode(tree);
    int start = 3;
    cout << Solution().amountOfTime(root, start) << endl;
    return 0;
}