class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        res = ['a'] * n
        k -= n
        i = n - 1
        while k >= 25:
            res[i] = 'z'
            print(i, res)
            k -= 25
            i -= 1
        if i >= 0:
            res[i] = chr(ord('a') + k)
        return ''.join(res)

if __name__ == '__main__':
    print(Solution().getSmallestString(5, 130))