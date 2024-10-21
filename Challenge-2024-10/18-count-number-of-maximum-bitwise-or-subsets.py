from typing import List


class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        res = 0
        max_or = 0
        for n in nums:
            max_or = max_or | n

        def helper(index, current_or, max_or):
            nonlocal res
            if index == len(nums) and current_or == max_or:
                res += 1
            if index < len(nums):
                helper(index + 1, current_or, max_or)
                helper(index + 1, current_or | nums[index], max_or)

        helper(0, 0, max_or)
        return res
