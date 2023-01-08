class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        patterns = list(pattern)
        ss = s.split(' ')
        p2s = {}
        s2p = {}
        if (len(pattern) != len(ss)):
            return False
        for px, sx in zip(patterns, ss):
            p2s[px] = sx
            s2p[sx] = px
        p2s_construct = ' '.join([p2s[x] for x in patterns])
        s2p_construct = ''.join([s2p[x] for x in ss])
        return p2s_construct == s and s2p_construct == pattern

if __name__ == '__main__':
    pattern = 'abba'
    s = 'dog cat cat dog'
    print(Solution().wordPattern(pattern, s))
        