class Item:
    def __init__(self, c, n):
        self.char = c
        self.count = n

    def __lt__(self, other):
        if ord(self.char) > ord(other.char):
            return True
        return False
    
    def __repr__(self):
        return f'({self.char}, {self.count})'

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:

        import heapq

        ct = {}
        for c in s:
            if c not in ct:
                ct[c] = 0
            ct[c] += 1

        pq = []
        for k in ct:
            heapq.heappush(pq, Item(k, ct[k]))

        res = ''

        while len(pq) > 0:
            tp = heapq.heappop(pq)
            if len(res) > 0:
                if res[-1] == tp.char:
                    if len(pq) > 0:
                        tp2 = heapq.heappop(pq)
                        res = res + tp2.char
                        tp2.count -= 1
                        if tp2.count > 0:
                            heapq.heappush(pq, tp2)
                    else:
                        return res
                else:
                    for _ in range(min(repeatLimit, tp.count)):
                        res = res + tp.char
                        tp.count -= 1
            else:
                for _ in range(min(repeatLimit, tp.count)):
                    res = res + tp.char
                    tp.count -= 1

            if tp.count > 0:
                heapq.heappush(pq, tp)

        return res
