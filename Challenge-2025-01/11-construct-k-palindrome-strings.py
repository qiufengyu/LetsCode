class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        from collections import Counter

        if len(s) < k:
            return False

        c = Counter(s)
        odd = 0
        for _, v in c:
            if v % 2 == 1:
                odd += 1

        return odd < k
