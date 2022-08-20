#include "../header.h"

class Solution {
    int find(vector<int>& ds, int i) {
        if (ds[i] < 0) {
            return i;
        } else {
            ds[i] = find(ds, ds[i]);
            return ds[i];
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ds(s.size(), -1);
        unordered_map<int, vector<int>> m;
        for (vector<int>& p: pairs) {
            int i = find(ds, p[0]), j = find(ds, p[1]);
            if (i != j) {
                ds[j] = i;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            m[find(ds, i)].push_back(i);
        }
        for (auto& e: m) {
            string temp = "";
            for (int x: e.second) {
                temp.push_back(s[x]);
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < e.second.size(); ++i) {
                s[e.second[i]] = temp[i];
            }
        }
        return s;
    }
};