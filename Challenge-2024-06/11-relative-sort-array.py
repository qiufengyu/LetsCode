from typing import List


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        mp = dict()
        l = len(arr2)
        for i in range(len(arr2)):
            mp[arr2[i]] = i
        return sorted(arr1, key=lambda x: mp.get(x, l + x))