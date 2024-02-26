from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        ct = Counter(s)
        res = ''
        for k, v in ct.most_common():
            res += (k * v)
        return res
