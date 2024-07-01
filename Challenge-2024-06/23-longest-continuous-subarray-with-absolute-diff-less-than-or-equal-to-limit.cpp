#include "../header.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ, minQ;
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.size()) {
            while (!maxQ.empty() && maxQ.back() < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[right]);
            while (!minQ.empty() && minQ.back() > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(nums[right]);
            while (maxQ.front() - minQ.front() > limit) {
                if (maxQ.front() == nums[left]) {
                    maxQ.pop_front();
                }
                if (minQ.front() == nums[left]) {
                    minQ.pop_front();
                }
                left++;
            }            
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};