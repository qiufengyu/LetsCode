#include "../header.h"

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = (int)shifts.size() - 2; i >= 0; --i) {            
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;            
        }
        for (int i = 0; i < s.size(); ++i) {
            s[i] = 'a' + ((s[i] - 'a' + shifts[i]) % 26);
        }
        return s;
    }
};

int main() {
    string s;
    string sv;
    cin >> s >> sv;
    vector<int> shifts = stringToIntegerVector(sv);
    cout << Solution().shiftingLetters(s, shifts) << endl;
    return 0;
}