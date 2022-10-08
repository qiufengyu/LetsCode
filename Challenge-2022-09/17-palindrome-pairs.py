from typing import List


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        w2i = {words[i]: i for i in range(len(words))}
        words = sorted(words, key=len)
        # important to avoid TLE: first filter by length
        # need to filter out if the candidate rest could not be in the w2v
        len_set = set([len(word) for word in words])
        res = []
        for word in words:
            rword = word[::-1]
            # case 1
            if rword in w2i and w2i[rword] != w2i[word]:
                res.append([w2i[word], w2i[rword]])
            wl = 0
            wr = len(word)
            # case 2
            for i in range(wr, wl, -1):
                if (wr - i) in len_set:
                    rest = word[i:]
                    rest = rest[::-1]
                    # secondly, if rest is not find, no need to judge padindrome
                    if rest in w2i and w2i[word] != w2i[rest] and self._is_palindrome(word, 0, i-1):
                        #print(word, w2i[word], rest, w2i[rest], "rest + word")
                        res.append([w2i[rest], w2i[word]])
                if (i - 1) in len_set:
                    rest = word[:i-1]        
                    rest = rest[::-1]
                    if rest in w2i and w2i[word] != w2i[rest] and self._is_palindrome(word, i-1, wr-1):
                        # print(word, w2i[word], rest, w2i[rest], "word + rest")
                        res.append([w2i[word], w2i[rest]])
        return res

    def _is_palindrome(self, word: str, left: int, right: int) -> bool:
        while left < right:
            if word[left] != word[right]:
                return False
            left += 1
            right -= 1
        return True


if __name__ == '__main__':
    words = ["a",""]
    res = Solution().palindromePairs(words)
    print(res)