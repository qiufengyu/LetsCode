from typing import List


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        st = set(dictionary)
        n = len(s)
        dp = [n for _ in range(len(s))]
        dp[0] = 0 if s[0:1] in st else 1
        for i in range(1, n):
            for j in range(i, 0, -1):
                dp[i] = min(dp[i], dp[j - 1] + (0 if s[j:i+1] in st else i - j + 1))
            dp[i] = min(dp[i], (0 if s[0:i+1] in st else i+1))
        return dp[-1]
