from typing import List

import bisect

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        res = 0
        idx = 0
        while idx < len(nums):
            l, u = lower - nums[idx], upper - nums[idx]
            left = bisect.bisect_left(nums, l)
            right = bisect.bisect_right(nums, u)
            res += right - left
            if left <= idx and right > idx:
                res -= 1
            idx += 1
        return res // 2
