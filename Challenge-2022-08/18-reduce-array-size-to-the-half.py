import collections
from typing import List
import math

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        to_be_removed = math.ceil(len(arr) / 2)
        removed = 0
        res = 0
        counter = collections.Counter(arr).items()
        counter = sorted(counter, key=lambda x: x[1], reverse=True)
        for i in counter:
            if removed < to_be_removed:
                removed += i[1]
                res += 1
            else:
                break
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.minSetSize([3,3,3,3,3,3]))
