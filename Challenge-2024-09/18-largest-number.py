from typing import List
from functools import cmp_to_key


def cmp_num(num1: int, num2: int):
    s1, s2 = str(num1), str(num2)
    if s1 + s2 < s2 + s1:
        return 1
    elif s1 + s2 > s1 + s2:
        return -1
    return 0
    


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums.sort(key=cmp_to_key(cmp_num), reverse=True)
        return ''.join([str(x) for x in nums])
