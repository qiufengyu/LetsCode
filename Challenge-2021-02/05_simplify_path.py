class Solution:
    def simplifyPath(self, path: str) -> str:
        folders = [x for x in path.split('/') if x]
        res = []
        for folder in folders:
            if folder == '..':
                if len(res) > 0:
                    res.pop()
            elif folder != '.':
                res.append(folder)
        return '/' + '/'.join(res)
