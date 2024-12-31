from typing import List

import heapq

class Item:
    def __init__(self, num, index):
        self.num = num
        self.index = index

    def __lt__(self, other):
        if self.num < other.num:
            return True
        if self.num == other.num:
            return self.index < other.index
        return False
    
    def __repr__(self):
        return f'({self.num}, {self.index})'


class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        n = len(nums)
        pq = []
        for i in range(n):
            heapq.heappush(pq, Item(nums[i], i))
        for i in range(k):
            tp = heapq.heappop(pq)
            nums[tp.index] *= multiplier
            heapq.heappush(pq, Item(nums[tp.index], tp.index))
        return nums

if __name__ == '__main__':
    s = Solution()
    r = s.getFinalState([2,1,3,5,6], 5, 2)
    print(r)

