class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        p = 1
        nums = set()
        while p < 2**31:
            p_list = sorted(str(p))
            nums.add(''.join(p_list))
            p = p * 2
        return ''.join(sorted(str(n))) in nums


