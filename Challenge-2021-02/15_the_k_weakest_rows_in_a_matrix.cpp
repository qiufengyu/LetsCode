#include "../header.h"

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, set<int>> m;
        for (int i = 0; i < mat.size(); i++) {
          auto v = mat[i];
          int s = accumulate(v.begin(), v.end(), 0);
          m[s].insert(i);
        }
        int count = 0;
        vector<int> temp;
        for (auto e: m) {
          temp.insert(temp.end(), e.second.begin(), e.second.end());
          count += e.second.size();
          if (count >= k) {
            break;
          }
        }
        vector<int> res;
        res.insert(res.end(), temp.begin(), temp.begin() + k);
        return res;
    }
};