import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        c_sqrt = int(math.sqrt(c)) + 1
        all_squares = [x*x for x in range(c_sqrt)]
        all_c_squares = [c - x for x in all_squares]
        s1 = set(all_squares)
        s2 = set(all_c_squares)
        return len(s1.intersection(s2)) > 0
