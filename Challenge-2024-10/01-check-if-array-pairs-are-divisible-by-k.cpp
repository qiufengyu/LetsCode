#include "../header.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int i = 0;i < arr.size(); i++) {
            mp[((arr[i] % k) + k) % k] += 1;
        }
        for (auto const& p: mp) {
            if (p.first != 0 && mp[k - p.first] != p.second) {
                return false;
            }
        }
        return (mp[0] % 2) == 0;
    }
};