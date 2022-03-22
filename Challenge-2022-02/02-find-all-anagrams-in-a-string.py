from typing import List


class Solution:
    def compare(self, a: List[int], b: List[int]) -> bool:
        for i in range(26):
            if a[i] != b[i]:
                return False
        return True

    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        res = []
        pd = [0] * 26
        for c in p:
            pd[ord(c) - 97] += 1
        sd = [0] * 26
        for i in range(len(p)):
            sd[ord(s[i]) - 97] += 1
        if self.compare(pd, sd):
            res.append(0)        
        for i in range(1, len(s) - len(p) + 1):
            to_decrease = ord(s[i-1]) - 97
            to_increase = ord(s[i+len(p)-1]) - 97
            sd[to_decrease] -= 1
            sd[to_increase] += 1
            if self.compare(pd, sd):
                res.append(i)
        return res

if __name__ == '__main__':
    s = input()
    p = input()
    print(Solution().findAnagrams(s, p))
