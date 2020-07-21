#include "header.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto x: nums) {
            ++m[x];
        }
        vector<pair<int, int>> v;
        for (auto e: m) {
            v.push_back(e);
        }
        sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) -> bool { return a.second > b.second; });
        int i = 0;
        while (i < k) {            
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = Solution().topKFrequent(nums, k);
    for (auto x: ans) {
        cout << x << " ";
    }
    return 0;
}