#include "../header.h"

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> charCount(26, 0);
        for (int i = 0; i < letters.size(); i++) {
            charCount[letters[i] - 'a']++;
        }
        int res = 0;
        helper(words, score, charCount, 0, 0, res);
        return res;
    }

    void helper(vector<string>& words, vector<int>& score, vector<int>& charCount, int index, int current, int& res) {
        for (int i = 0; i < 26; i++) {
            if (charCount[i] < 0) {
                return;
            }
        }
        res = max(res, current);
        for (int i = index; i < words.size(); i++) {
            string w = words[i];
            for (int j = 0; j < w.size(); j++) {
                charCount[w[j] - 'a']--;
                current += score[w[j] - 'a'];
            }
            helper(words, score, charCount, i + 1, current, res);
            for (int j = 0; j < w.size(); j++) {
                charCount[w[j] - 'a']++;
                current -= score[w[j] - 'a'];
            }
        }
    }
};