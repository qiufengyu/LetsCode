from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        tmp = [(x, y) for (x, y) in zip(names, heights)]
        tmp.sort(key=lambda x: -x[1])
        return [x for (x, y) in tmp]