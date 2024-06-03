from typing import List, Set


class Solution:
    
    res = []
    current = []

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.res = []
        self.current = []
        wordSet = set(wordDict)
        self.helper(s, wordSet, 0)
        return self.res

    def helper(self, s: str, wordSet: Set[str], index: int) -> None:
        if index >= len(s):
            if ''.join(self.current) == s:
                self.res.append(' '.join(self.current))
            return
        for i in range(index, len(s)):
            if s[index:i+1] in wordSet:
                self.current.append(s[index:i+1])
                self.helper(s, wordSet, i + 1)
                self.current.pop()