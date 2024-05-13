class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n, res = len(s), 1
        dp = [0] * 26
        for i in range(n):
            idx = ord(s[i]) - ord('a')
            for j in range(idx, max(-1, idx-k-1), -1):
                dp[idx] = max(dp[idx], dp[j]+1)
            for j in range(idx+1, min(26, idx+k+1)):
                dp[idx] = max(dp[idx], dp[j]+1)
            res = max(dp[idx], res)
        return res

# package main

# import "math"

# func longestIdealString(s string, k int) int {
# 	n := len(s)
# 	dp := make([]int, n)
# 	res := 0
# 	dp[0] = 1
# 	for i := 1; i < n; i += 1 {
# 		for j := i - 1; j >= 0; j -= 1 {
# 			if math.Max(s[i] - s[j], s[j] - s[i]) <= k {
# 				dp[i] = math.Max(dp[i], dp[j]+1)
# 			}
# 		}
# 		res = math.MaxInt(res, dp[i])
# 	}
# }
