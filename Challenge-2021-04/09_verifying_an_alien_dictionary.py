class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map = {}
        for i in range(26):
            order_map[order[i]] = i
        for i in range(len(words) - 1):
            p = words[i]
            n = words[i+1]
            ml = min(len(p), len(n))
            idx = -1
            for j in range(ml):
                if order_map[p[j]] > order_map[n[j]]:
                    return False
                elif order_map[p[j]] < order_map[n[j]]:
                    idx = j
                    break
            if idx == -1 and len(p) > len(n):
                return False
        return True
