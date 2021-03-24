from typing import List

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        res: List[str] = []
        origin_set = set()
        case_dict = {}
        vowel_dict = {}
        for x in wordlist:
            origin_set.add(x)
            x_lower = x.lower()
            if x_lower not in case_dict:
                case_dict[x_lower] = x
            x_vowel = x_lower.replace('a', '_').replace('e', '_').replace('i', '_').replace('o', '_').replace('u', '_')
            if x_vowel not in vowel_dict:
                vowel_dict[x_vowel] = x
        print(case_dict)
        print(vowel_dict)
        for q in queries:
            if q in origin_set:
                res.append(q)
            else:
                q_lower = q.lower()
                if q_lower in case_dict:
                    res.append(case_dict[q_lower])
                else:
                    q_vowel = q_lower.replace('a', '_').replace('e', '_').replace('i', '_').replace('o', '_').replace('u', '_')
                    if q_vowel in vowel_dict:
                        res.append(vowel_dict[q_vowel])
                    else:
                        res.append('')
        return res


if __name__ == '__main__':
    s = Solution()
    wordlist = ["KiTe","kite","hare","Hare"]
    queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
    print(s.spellchecker(wordlist, queries))