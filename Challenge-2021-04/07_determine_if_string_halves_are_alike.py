class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set(list('AEIOUaeiou'))
        l = len(s) // 2
        lc = 0
        rc = 0
        for c in range(l):
            if s[c] in vowels:
                lc += 1
            if s[l+c] in vowels:
                rc += 1
        return lc == rc
