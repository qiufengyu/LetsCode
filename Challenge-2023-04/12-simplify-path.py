class Solution:
    def simplifyPath(self, path: str) -> str:
        tokens = path.split('/')
        new_path = []
        for t in tokens:
            if len(t) > 0:
                if t == '..':
                    if len(new_path) > 0:
                        new_path.pop()
                elif t != '.':
                    new_path.append(t)
        return '/' + '/'.join(new_path)
    