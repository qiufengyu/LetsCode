class Solution:
    def findKthBit(self, n: int, k: int) -> str:

        def ri(s: str) -> str:
            sl = ['1' if x == '0' else '0' for x in s]
            sl.reverse()
            return ''.join(sl)

        s = '0'
        while n > 1:
            s = s + '1' + ri(s)
            n -= 1
        return s[k-1]