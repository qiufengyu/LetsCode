class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        [r1, i1] = num1.split('+')
        [r2, i2] = num2.split('+')
        nr1 = int(r1)
        nr2 = int(r2)
        ni1 = int(i1[:-1])
        ni2 = int(i2[:-1])
        rr = str(nr1 * nr2 - ni1 * ni2)
        ri = str(nr1 * ni2 + nr2 * ni1)
        return rr + '+' + ri + 'i'


if __name__ == '__main__':
    s = Solution()
    res = s.complexNumberMultiply('1+-1i', '1+-1i')
    print(res)