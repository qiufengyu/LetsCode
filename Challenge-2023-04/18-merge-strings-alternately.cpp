#include "../header.h"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while (i < word1.size()) {
            res.push_back(word1[i++]);
        }
        while (j < word2.size()) {
            res.push_back(word2[j++]);
        }
        return res;
    }
};