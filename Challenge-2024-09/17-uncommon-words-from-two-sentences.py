from typing import Counter, List


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        all_string = s1.split()
        all_string += (s2.split())
        counter = Counter(all_string)

        ans = []
        for s, cnt in counter.items():
            if cnt == 1:
                ans.append(s)
        return ans