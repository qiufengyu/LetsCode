class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        totalCount = 2 ** k
        l = len(s)
        subSet = set()
        for i in range(l - k + 1):
            subSet.add(s[i:i+k])
        return totalCount == len(subSet)
