from collections import Counter


class Solution:
    def minSteps(self, s: str, t: str) -> int:    
        c1 = Counter(s)
        c2 = Counter(t)
        l = 0
        for k in c1:
            if k in c2:
                l += min(c1[k], c2[k])
        return len(s) - l