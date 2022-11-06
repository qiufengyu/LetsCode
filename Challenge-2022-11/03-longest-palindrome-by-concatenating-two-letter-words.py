from collections import Counter
from typing import List


class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ws = Counter(words)
        res = 0
        for w in ws:
            rw = w[::-1]
            if rw in ws and ws[rw] > 0:
                if w == rw:
                    if ws[w] > 1:
                        res += 4 * (ws[w] // 2)
                        ws[w] -= (2 * (ws[w] // 2))
                else:
                    cnt = min(ws[w], ws[rw])
                    res += 4 * cnt
                    ws[w] = ws[w] - cnt if ws[w] - cnt > 0 else 0
                    ws[rw] = ws[rw] - cnt if ws[rw] - cnt > 0 else 0
        for w in ws:
            if ws[w] > 0 and w == w[::-1]:
                return res + 2
        return res
    
