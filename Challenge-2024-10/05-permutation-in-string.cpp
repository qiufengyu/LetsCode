#include "../header.h"

class Solution {
    bool check(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto const& p: m1) {
            if (m2.count(p.first) == 0) {
                return false;
            }
            if (m2[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (check(m1, m2)) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            m2[s2[i]]++;
            m2[s2[i - s1.size()]]--;
            if (m1.count(s2[i]) != 0 && check(m1, m2)) {
                return true;
            }
        }
        return false;
    }
};