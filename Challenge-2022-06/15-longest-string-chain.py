from typing import List

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        m = {}
        dp = [1] * len(words)
        for i in range(len(words)):
            m[words[i]] = i
            if len(words[i]) > 1:
                for j in range(len(words[i])):
                    s = words[i][:j] + words[i][j+1:]
                    if s in m:
                        dp[i] = max(dp[i], dp[m[s]] + 1)
        return max(dp)


if __name__ == '__main__':
    s = Solution()
    s.longestStrChain(["a","b","ba","bca","bda","bdca"])