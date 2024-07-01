from typing import List


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split(' ')
        dictionary.sort(key=lambda x: len(x))
        res = []
        for w in words:
            match = False
            for d in dictionary:
                if w.startswith(d):
                    match = True
                    res.append(d)
                    break
            if not match:
                res.append(w)                    
        return ' '.join(res)