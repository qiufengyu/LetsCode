#include "../header.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int gs = 2 * numRows - 2;
        int g = s.size() / gs;
        string res;
        // first row only
        for (int j = 0; j <= g; ++j) {
            if (j * gs < s.size()) {
                res.push_back(s[j*gs]);
            }
        }
        for (int i = 1; i < numRows; ++i) {
            int p = 0;
            for (int j = 0; j <= g; ++j) {
                p = j * gs + i;
                if (p < s.size()) {
                    res.push_back(s[p]);
                }
                if (i != numRows - 1) {
                    p = j * gs + gs - i;
                    if (p < s.size()) {
                        res.push_back(s[p]);
                    }
                }
            }            
        }
        return res;    
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << Solution().convert(s, n) << endl;
    return 0;
}