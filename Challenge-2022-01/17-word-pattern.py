class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_parts = s.split(' ')
        if len(pattern) != len(s_parts):
            return False
        p2s = {}
        s2p = {}
        for i in range(len(pattern)):
            if pattern[i] in p2s and s_parts[i] in s2p:
                if p2s[pattern[i]] != s_parts[i] or s2p[s_parts[i]] != pattern[i]:
                    return False
            elif pattern[i] in p2s or s_parts[i] in s2p:
                return False
            else:
                p2s[pattern[i]] = s_parts[i]
                s2p[s_parts[i]] = pattern[i]
        return True


if __name__ == '__main__':
    s = Solution()
    print(s.wordPattern('aaaa', 'dog cat cat dog'))