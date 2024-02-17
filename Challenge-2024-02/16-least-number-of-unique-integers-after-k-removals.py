from collections import Counter
from typing import List


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        c = Counter(arr)
        all = len(c)
        least_common = c.most_common()[::-1]
        for kk, vv in least_common:
            if k - vv >= 0:
                k -= vv
                all -= 1
            else:
                break
        return all