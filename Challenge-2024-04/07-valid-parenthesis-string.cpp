#include "../header.h"

class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0, star = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                l++;
            } else if (s[i] == ')') {
                r++;
            } else {
                star++;
            }
            if (r > l && star < r - l) {
                return false;
            }
        }
        if (star < abs(l - r)) {
            return false;
        }
        l = 0;
        r = 0;
        star = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                l++;
            } else if (s[i] ==')') {
                r++;
            } else {
                star++;
            }
            if (l > r && star < l - r) {
                return false;
            }
        }
        if (star < abs(l - r)) {
            return false;
        }
        return true;
    }
};

int main() {
    string s = "***((";
    cout << Solution().checkValidString(s) << endl;
    return 0;
}