from typing import Counter, List
import functools

def cmp(a: tuple, b: tuple) -> int:
    if a[1] != b[1]:
       return -1 if a[1] < b[1] else 1
    return -1 if a[0] > b[0] else 1

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        ctr = Counter(nums)
        tmp = [(k, v) for (k, v) in ctr.items()]
        tmp.sort(key=functools.cmp_to_key(cmp))
        res = [0] * len(nums)
        idx = 0
        for (k, v) in tmp:
            for i in range(idx, idx + v):
                res[i] = k
            idx += v
        return res
