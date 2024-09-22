from typing import List


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        lst = list(range(1, n+1))
        return sorted(lst, key=lambda x: str(x))
        