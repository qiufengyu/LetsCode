#include "../header.h"

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp1, mp2;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            mp1[target[i]]++;
            mp2[arr[i]]++;
        }
        for (auto const& p: mp1) {
            if (mp2.count(p.first) == 0 || mp2[p.first] != p.second) {
                return false;
            }
        }
        for (auto const& p: mp2) {
            if (mp1.count(p.first) == 0 || mp1[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
};