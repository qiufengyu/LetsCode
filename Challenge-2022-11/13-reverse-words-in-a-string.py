class Solution:
    def reverseWords(self, s: str) -> str:
        tokens = [x for x in s.split(' ') if x]
        tokens.reverse()
        return ' '.join(tokens)