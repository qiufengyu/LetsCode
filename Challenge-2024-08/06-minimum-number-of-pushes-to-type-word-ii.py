from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        counter = Counter(word)
        res = 0
        index = 0
        for (k, v) in counter.most_common():
            res += v * (index // 8 + 1)
            index += 1
        return res
