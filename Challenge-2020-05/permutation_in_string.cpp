#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1v(26, 0);
        vector<int> s2v(26, 0);
        int m = s1.size();
        int n = s2.size();
        if (n < m) {
            return false;
        }
        for(auto &c: s1) {
            s1v[c-'a'] += 1;
        }
        for(int i = 0; i<m; i++) {
            s2v[s2[i]-'a'] += 1;
        }
        auto pair = std::mismatch(s1v.begin(), s1v.end(), s2v.begin());
        if (pair.first == s1v.end() && pair.second == s2v.end()) {
            return true;
        }
        for (int j = m; j < n; j++) {
            s2v[s2[j]-'a'] += 1;
            s2v[s2[j-m]-'a'] -= 1;
            pair = std::mismatch(s1v.begin(), s1v.end(), s2v.begin());
            if (pair.first == s1v.end() && pair.second == s2v.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << Solution().checkInclusion(s1, s2) << endl;
}