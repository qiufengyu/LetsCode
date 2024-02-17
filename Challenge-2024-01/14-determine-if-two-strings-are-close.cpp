#pragma GCC optimize("O3", "unroll-loops")

#include "../header.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if (l1 == l2) {
            unordered_map<char, int> m1, m2;
            unordered_set<char> s1, s2;
            for (int i = 0; i < l1; i++) {
                m1[word1[i]]++;
                m2[word2[i]]++;
                s1.insert(word1[i]);
                s2.insert(word2[i]);
            }
            if (m1.size() == m2.size() && s1 == s2) {
                unordered_map<int, int> rm1, rm2;
                for (auto const& p: m1) {
                    rm1[p.second]++;
                }
                for (auto const& p: m2) {
                    rm2[p.second]++;
                }
                return rm1 == rm2;
            }
        }
        return false;        
    }
};