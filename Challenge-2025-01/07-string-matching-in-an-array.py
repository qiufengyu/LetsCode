class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        for word in words:
            for w in words:
                if len(w) > len(word) and word in w:
                    res.append(word)
                    break
        return res