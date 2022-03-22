#include "../header.h"

class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        size_t l = s.size();
        int i = 0;
        bool sign = true;
        while (s[i] == ' ') {
            ++i;
        }
        if (s[i] == '-') {
            sign = false;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }
        while (s[i] == '0') {
            ++i;
        }
        while (i < l && isdigit(s[i])) {
            long temp = (long)res * 10L + (s[i] - '0');
            // test if overflow
            if (temp > INT_MAX) {                
                return sign ? INT_MAX : INT_MIN;
            }
            res = temp;
            ++i;
        }
        return sign ? res : (-res);
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().myAtoi(s) << endl;
    return 0;
}