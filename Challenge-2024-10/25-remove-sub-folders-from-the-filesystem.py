from typing import List


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        n = len(folder)
        res = [folder[0]]
        for i in range(1, n):
            prev, current = res[-1], folder[i]
            if current.startswith(prev) and len(prev) < len(current) and current[len(prev)] == '/':
                continue
            else:
                res.append(current)
        return res
