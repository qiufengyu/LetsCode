class Solution:
    def fractionAddition(self, expression: str) -> str:
        nums = list(map(int, re.findall(r'[+-]?\d+', expression)))
        numerator, denominator = 0, 1

        for i in range(0, len(nums), 2):
            num, den = nums[i], nums[i+1]
            numerator = numerator * den + num * denominator
            denominator *= den
            _gcd = gcd(numerator, denominator)
            numerator = numerator // _gcd
            denominator = denominator // _gcd
        
        return f'{numerator}/{denominator}'