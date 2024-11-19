#include "../header.h"

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ps(n+1, 0);
        for (int i = 0; i < n; i++) {
            ps[i+1] = ps[i] + nums[i];
        }

        deque<int> dq;
        int res = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && ps[i] - ps[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && ps[i] <= ps[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }

    // TLE -> O(n^2)
    int shortestSubarray2(vector<int>& nums, int k) {
        int n = nums.size(), res = -1;
        vector<long long> ps1(n, 0), ps2(n, 0);
        ps1[0] = nums[0];
        ps2[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            ps1[i] = ps1[i-1] + nums[i];
            ps2[n-1-i] = ps2[n-i] + nums[n-i-1];
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                long long left = i > 0 ? ps1[i-1] : 0LL;
                long long right = i + l < n ? ps2[i+l] : 0LL;
                if (sum - left - right >= k) {
                    return l;
                } 
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{2, -1, 2};
    int k = 3;
    cout << Solution().shortestSubarray(nums, k) << endl;
    return 0;
}