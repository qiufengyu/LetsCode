from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        res = ''
        for (k, v) in c.most_common():
            res = res + (k * int(v))
        return res