#include "../header.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> m1, m2, mt;
        for (string const& word2: words2) {
            mt.clear();
            for (char const& c: word2) {
                ++mt[c];
            }
            for (pair<char, int> const& p: mt) {
                m2[p.first] = max(p.second, m2[p.first]);
            }
        }
        vector<string> res;
        bool flag = true;
        for (string const& word1: words1) {
            m1.clear();
            flag = true;
            for (char const& c: word1) {
                ++m1[c];
            }
            for (pair<char, int> const& p: m2) {
                if (m2[p.first] > m1[p.first]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word1);
            }
        }
        return res;
    }
};