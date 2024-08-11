#include "../header.h"

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto const& s: arr) {
            mp[s]++;
        }
        vector<string> v(arr.size(), "");
        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (mp[arr[i]] == 1) {
                v[j++] = arr[i];
            }
        }
        return v[k-1];
    }
};