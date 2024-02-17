#include "../header.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size(), carry = 0;
        while (k > 0 && n > 0) {
            int temp = num[n-1] + (k % 10) + carry;
            if (temp >= 10) {
                temp = temp % 10;
                carry = 1;
            } else {
                carry = 0;
            }            
            num[n-1] = temp;
            k = k / 10;
            --n;
        }
        while (k > 0) {
            int temp = k % 10 + carry;
            if (temp >= 10) {
                carry = 1;
                temp = temp % 10;
            } else {
                carry = 0;
            }
            num.insert(num.begin(), temp);
            k = k / 10;
        }
        while (n > 0) {
            int temp = num[n-1] + carry;
            if (temp >= 10) {
                carry = 1;
                temp = temp % 10;
            } else {
                carry = 0;
            }
            num[n-1] = temp;
            --n;
        }
        if (carry == 1) {
            num.insert(num.begin(), 1);
        }
        return num;
    }
};