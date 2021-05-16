

class Solution:
    def memLeak(self, memory1: int, memory2: int):
        count = 1
        while count <= memory1 or count <= memory2:
            if memory1 < memory2:
                memory2 -= count
            else:
                memory1 -= count
            count += 1
        return [count, memory1, memory2]

if __name__ == '__main__':
    s = Solution()
    r = s.memLeak(8,10)
    print(r)