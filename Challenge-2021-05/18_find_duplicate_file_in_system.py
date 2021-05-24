from typing import List


class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        res = []
        m = {}
        for path in paths:
            parts = path.split(' ')
            p = parts[0]
            files = parts[1:]
            for f in files:
                filename_content = f.split('(')
                filename = filename_content[0]
                content = filename_content[1][:-1]
                full_path = p + '/' + filename
                if content in m:
                    m[content].append(full_path)
                else:
                    m[content] = [full_path]
        for c in m:
            if len(m[c]) > 1:
                res.append(m[c])
        return res

if __name__ == '__main__':
    s = Solution()
    res = s.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"])
    print(res)
