from typing import List


class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        file2path = {}
        res = []
        for path in paths:
            parts = path.split(' ')
            dir = parts[0]
            for f in parts[1:]:
                fc = f.split('(')
                fp = dir + '/' + fc[0]
                c = fc[1][:-1]
                if c in file2path:
                    file2path[c].append(fp)
                else:
                    file2path[c] = [fp]
        for k in file2path:
            if len(file2path[k]) > 1:
                res.append(file2path[k])
        return res
