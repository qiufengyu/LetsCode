class Solution:
    def simplifyPath(self, path: str) -> str:
        folders = path.split('/')
        res = []
        for folder in folders:
            if folder == '..':
                if len(res) > 0:
                    res.pop()
            elif folder == '.':
                continue
            elif len(folder) > 0:
                res.append(folder)
        return '/' + '/'.join(res)