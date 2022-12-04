from collections import Counter, OrderedDict


class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        d = {}
        for x in c:
            if -c[x] in d:
                d[-c[x]].append(x)
            else:
                d[-c[x]] = [x]
        res = ''
        for x in sorted(d):
            l = d[x]
            for xx in l:
                res += (xx * (-x))
        return res

if __name__ == '__main__':
    s = Solution()
    r = s.frequencySort('tree')
    print(r)
