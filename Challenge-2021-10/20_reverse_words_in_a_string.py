class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split(' ')
        words = [x for x in words if len(x) > 0]
        words.reverse()
        return ' '.join(words)
        