#include "../header.h"

class Solution {
public:
    int maximum69Number(int num) {
        int n4 = num / 1000, n3 = (num % 1000) / 100;
        int n2 = (num % 100) / 10, n1 = num % 10;
        if (n4 == 6) {
            return num + 3000;
        }
        if (n3 == 6) {
            return num + 300;
        }
        if (n2 == 6) {
            return num + 30;
        }
        if (n1 == 6) {
            return num + 3;
        }
        return num;        
    }
};