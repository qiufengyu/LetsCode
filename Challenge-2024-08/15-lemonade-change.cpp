#include "../header.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                c5++;
            } else if (bills[i] == 10) {
                if (c5 <= 0) {
                    return false;
                } else {
                    c5--;
                }
                c10++;
            } else {
                if (c5 <= 0) {
                    return false;
                } else if (c10 <= 0) {
                    if (c5 < 3) {
                        return false;
                    } else {
                        c5 -= 3;
                    }
                } else {
                    c10--;
                    c5--;
                }
            }
        }
        return true;        
    }
};