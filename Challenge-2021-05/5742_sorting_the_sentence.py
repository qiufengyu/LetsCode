class Solution:
  def sortSentence(self, s: str) -> str:
    ls = [x[::-1] for x in s.split()]
    ls.sort()
    lss = [x[-1:0:-1] for x in ls]
    return ' '.join(lss)

if __name__ == '__main__':
  s = Solution()
  r = s.sortSentence('is2 sentence4 This1 a3')
  print(r)

