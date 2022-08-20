import functools
from typing import List

def compare(a: tuple, b: tuple) -> int:
    if a[1] < b[1]:
        return -1
    if a[1] > b[1]:
        return 1
    if a[0] < b[0]:
        return -1
    return 1

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m = len(mat)
        pq = [(i, sum(mat[i])) for i in range(m)]
        pq.sort(key=functools.cmp_to_key(compare))
        res = [i[0] for i in pq]        
        return res[:k]

if __name__ == '__main__':
    mat = [[1,0,0,0],
            [1,1,1,1],
            [1,0,0,0],
            [1,0,0,0]]
    k = 3
    print(Solution().kWeakestRows(mat, k))
