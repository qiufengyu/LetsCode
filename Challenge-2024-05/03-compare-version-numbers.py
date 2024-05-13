class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1s, v2s = version1.split('.'), version2.split('.')
        l1, l2 = len(v1s), len(v2s)
        while l1 < l2:
            v1s.append('0')
            l1 += 1
        while l2 < l1:
            v2s.append('0')
            l2 += 1
        for i in range(l1):
            v1, v2 = int(v1s[i]), int(v2s[i])
            if v1 < v2:
                return -1
            elif v1 > v2:
                return 1
        return 0