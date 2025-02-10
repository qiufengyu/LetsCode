from typing import List


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        res = 0
        n = len(words)
        for i in range(n):
            for j in range(i + 1, n):
                if len(words[i]) <= len(words[j]) and words[j].startswith(words[i]) and words[j].endswith(words[i]):
                    res += 1
        return res