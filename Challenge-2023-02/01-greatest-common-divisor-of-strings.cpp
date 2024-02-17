#include "../header.h"

class Solution {
    bool divide(string& s, string& d) {
        int dn = d.size();
        for (int i = 0; i < s.size() / d.size(); ++i) {
            for (int j = 0; j < dn; ++j) {
                if (s[i*dn + j] != d[j]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size()) {
            swap(str2, str1);
        }
        // str1 < str2
        int s1 = str1.size(), s2 = str2.size();
        int gcd0 = __gcd(s1, s2);
        vector<int> cds;
        for (int i = 1; i < sqrt(gcd0); ++i) {
            if (gcd0 % i == 0) {
                cds.push_back(i);
            }
        }
        cds.push_back(gcd0);
        for (int i = cds.size()-1; i >= 0; --i) {
            string s = str1.substr(0, cds[i]);
            if (divide(str1, s) && divide(str2, s)) {
                return s;
            }
        }
        // string r = str1.substr(0, 1);
        // if (divide(str1, r) && divide(str2, r)) {
        //     return r;
        // }
        return "";
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << Solution().gcdOfStrings(str1, str2) << endl;
    return 0;
}