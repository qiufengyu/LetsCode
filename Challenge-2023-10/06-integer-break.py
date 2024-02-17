class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        threes = n // 3
        remainer = n % 3
        res = 3 ** threes
        if remainer == 1:
            res //= 3
            res *= 4
        elif remainer == 2:
            res *= 2
        return int(res)