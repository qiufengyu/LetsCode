from collections import Counter


class Solution:
    def check(self, d: dict) -> int:
        sum = 0
        if 'a' in d:
            sum += d['a']
        if 'e' in d:
            sum += d['e']
        if 'i' in d:
            sum += d['i']
        if 'o' in d:
            sum += d['o']
        if 'u' in d:
            sum += d['u']
        return sum
    
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s) // 2
        h1, h2 = s[:n].lower(), s[n:].lower()
        c1 = Counter(h1)
        c2 = Counter(h2)
        return self.check(c1) == self.check(c2)