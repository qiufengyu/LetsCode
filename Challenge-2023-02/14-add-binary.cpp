#include "../header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int as = a.size(), bs = b.size();
        int mn = min(as, bs), mx = max(as, bs);
        if (as < bs) {
            swap(a, b);
        }
        string res(mx + 1, '0');
        int i = 0, carry = 0;
        while (i < mn) {
            int ca = a[mx-1-i] - '0', cb = b[mn-1-i] - '0';
            int cc = ca + cb + carry;
            if (cc > 1) {
                carry = 1;
            } else {
                carry = 0;
            }
            res[mx-i] = (cc % 2) + '0';
            ++i;
        }
        while (i < mx) {
            int ca = a[mx-1-i] - '0';
            int cc = ca + carry;
            if (cc > 1) {
                carry = 1;
            } else {
                carry = 0;
            }
            res[mx-i] = (cc % 2) + '0';
            ++i;
        }
        if (carry == 1) {
            res[0] = '1';
            return res;
        }
        return res.substr(1);
    }
};