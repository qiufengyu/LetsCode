from typing import List


class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n, count, res = len(nums), 0, 0
        countings = []
        for i in range(n):
            if nums[i] % 2 == 1:
                countings.append(count + 1)
                count = 0
            else:
                count += 1
        countings.append(count + 1)
        lc = len(countings)
        for i in range(lc - k):
            res += (countings[i] * countings[i + k])
        return res