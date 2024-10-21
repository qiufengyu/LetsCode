class Solution:
    def minimumSteps(self, s: str) -> int:
        zeros = 0
        zero_index, one_index = [], []
        for i in range(len(s)):
            if s[i] == '0':
                zeros += 1
                zero_index.append(i)
            else:
                one_index.append(i)
        res = 0
        for x in zero_index:
            if x >= zeros:
                res += (x - one_index[0])
                one_index.pop(0)
        return res