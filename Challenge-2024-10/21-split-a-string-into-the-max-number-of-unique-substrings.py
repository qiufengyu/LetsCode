class Solution:
    def maxUniqueSplit(self, s: str) -> int:

        res = 0
        
        def helper(start: int, end: int, current_split: list):           

            nonlocal res

            if end >= len(s):
                res = max(res, len(current_split))
                return                     

            for i in range(end, len(s)):
                nxt = s[end : i + 1]
                if nxt not in current_split:
                    current_split.append(nxt)
                    helper(i + 1, i + 1, current_split)
                    current_split.pop()

        for i in range(len(s)):
            helper(0, i+1, [s[0:i+1]])

        return res
