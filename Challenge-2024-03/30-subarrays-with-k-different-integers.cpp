#include "../header.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int start = 0, end = 0, n = nums.size(), res = 0;
        while (end < n) {
            mp[nums[end]]++;
            while (mp.size() > k && start <= end) {
                int x = nums[start];
                start++;
                mp[x]--;
                if (mp[x] == 0) {
                    mp.erase(x);
                }
            }
            int ss = start;
            while (mp.size() == k && ss <= end) {
                res++;
                // cout << ss << ": " << nums[ss] << ", " << end << ": " <<nums[end] << endl;
                int x = nums[ss];
                if (mp[x] == 1) {
                    break;
                }
                mp[x]--;
                ss++;
            }
            int sss = start;
            while (sss < ss) {
                mp[nums[sss]]++;
                sss++;
            }
            end++;
        }
        return res;
    }    
};

int main() {
    vector<int> nums{1,2,1,3,4};
    int k = 3;
    cout << Solution().subarraysWithKDistinct(nums, k) << endl;
}