from typing import List


class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def isBeautiful(current: List[int], n: int) -> bool:
            if len(current) == 0:
                return True
            for x in current:
                if n - x == k:
                    return False
            return True

        def helper(current: List[int], index: int) -> None:
            nonlocal res
            if index >= len(nums):
                return
            else:
                for i in range(index, len(nums)):
                    if isBeautiful(current, nums[i]):
                        current.append(nums[i])
                        res += 1
                        helper(current, i+1)
                        current.pop()

        res, current = 0, []
        nums = sorted(nums)
        helper(current, 0)
        return res
    
if __name__ == '__main__':
    nums = [2,2,2]
    k = 1
    res = Solution().beautifulSubsets(nums, k)
    print(res)