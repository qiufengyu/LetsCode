#include "../header.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shift(s.size() + 1, 0);
        for (int i = 0; i < shifts.size(); i++) {
            auto st = shifts[i];
            if (st[2] == 1) {
                shift[st[0]] += 1;
                shift[st[1]+1] -= 1;
            } else {
                shift[st[0]] -= 1;
                shift[st[1]+1] += 1;
            }
        }
        int currentShift = 0;
        for (int i = 0; i < s.size(); i++) {
            currentShift += shift[i];
            int offset = (currentShift % 26 + 26) % 26;
            s[i] = 'a' + ((s[i] - 'a' + offset) % 26);
        }
        return s;
    }
};

int main() {
    string s = "iaozjb";
    vector<vector<int> > shifts = {{0,4,0},{0,2,1},{1,3,1},{0,4,1},{4,4,1},{2,3,0},{5,5,0},{3,3,0},{2,3,0},{5,5,1},{5,5,1},{5,5,0}};
    cout << Solution().shiftingLetters(s, shifts) << endl;
    return 0;
}