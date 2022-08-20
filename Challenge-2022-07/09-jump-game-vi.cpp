#include "../header.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q{0};
        for (int i = 1; i < n; ++i) {
            // reuse nums to keep current value
            nums[i] = nums[q.front()] + nums[i];
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // keep size <= k
            while (i - q.front() >= k) {
                q.pop_front();
            }
        }
        return nums[n-1];
    }
};

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().maxResult(nums, k) << endl;
    return 0;
}