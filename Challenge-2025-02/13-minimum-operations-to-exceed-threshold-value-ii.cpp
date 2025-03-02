#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int res = 0;
        while (pq.top() < k) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(2 * x + y);
            res++;
        }
        return res;
    }
};

int main() {
    vector<int> nums{2,11,10,1,3};
    cout << Solution().minOperations(nums, 10) << endl;
    return 0;
}