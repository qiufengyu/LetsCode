class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(n // 2 + 1):
            sub = s[:i+1]
            if n % (i+1) == 0:
                times = n // (i + 1)
                if times > 1 and sub * times == s:
                    return True
        return False
    
if __name__ == '__main__':
    s = input()
    print(Solution().repeatedSubstringPattern(s))