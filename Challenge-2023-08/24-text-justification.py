from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        line = []
        width = 0
        for w in words:
            if width + len(w) + len(line) > maxWidth:
                # the spaces to add
                if len(line) == 1:
                    line[0] += (' ' * (maxWidth - width))
                else:
                    for i in range(maxWidth - width):                    
                        line[i % (len(line) - 1)] += ' '
                res.append(''.join(line))
                # init next line
                line = []
                width = 0
            line.append(w)
            width += len(w)
        # last line: left-align with one space only
        if len(line) > 0:
            last_line = ' '.join(line)
            last_line = last_line.ljust(maxWidth)
            res.append(last_line)
        return res