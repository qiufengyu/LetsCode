#include "../header.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        for (auto const& p: m) {
            if (s.count(p.second)) {
                return false;
            }
            s.insert(p.second);
        }
        return true;
    }
};