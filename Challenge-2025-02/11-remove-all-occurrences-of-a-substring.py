class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        removed = True
        while removed:
            ss = s.replace(part, '', 1)
            if len(ss) == len(s):
                removed = False
            s = ss
        return s