#include "../header.h"

class Solution {
    bool valid(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto const p: m1) {
            if (m2.count(p.first) == 0 || m2[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> m1, m2;
        for (char const& c: s1) {
            ++m1[c];
        }
        int l1 = s1.size();
        int i = 0;
        for (i = 0; i < l1 - 1; ++i) {
            ++m2[s2[i]];
        }
        for (i = l1 - 1; i < s2.size(); ++i) {
            ++m2[s2[i]];
            if (valid(m1, m2)) {
                return true;
            }
            --m2[s2[i-l1+1]];
        }
        return false;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().checkInclusion(s1, s2) << endl;
    return 0;
}