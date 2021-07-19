class Solution:
    def customSortString(self, order: str, str: str) -> str:
        m = {}
        for i, c in enumerate(order):
            m[c] = i
        return ''.join(sorted(list(str), key=lambda x: m[x] if x in m else 27))

if __name__ == '__main__':
    order = input()
    str = input()
    print(Solution().customSortString(order, str))