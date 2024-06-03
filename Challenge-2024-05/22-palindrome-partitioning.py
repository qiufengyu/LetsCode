from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(start: int, end: int) -> bool:
            while start < end:
                if s[start] == s[end]:
                    start += 1
                    end -= 1
                else:
                    return False
            return True

        def helper(res: List[List[str]], current: List[str], index: int) -> None:
            if index == len(s):
                tmp = []
                for x in current:
                    tmp.append(x)
                res.append(tmp)
                return
            else:
                for i in range(index, len(s)):
                    if isPalindrome(index, i):
                        current.append(s[index:i+1])
                        helper(res, current, i+1)
                        current.pop()
        res, current = [], []
        helper(res, current, 0)
        return res
    
if __name__ == '__main__':
    s = 'aab'
    res = Solution().partition(s)
    print(res)