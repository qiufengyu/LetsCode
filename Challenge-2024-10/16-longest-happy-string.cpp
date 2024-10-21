#include "../header.h"

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int endA = 0, endB = 0, endC = 0;
        while (a > 0 || b > 0 || c > 0) {
            if ((endA != 2 && a >= b && a >= c) || (a > 0 && (endB == 2 || endC == 2))) {
                res.push_back('a');
                endA++;
                endB = 0;
                endC = 0;
                a--;
            } else if ((endB != 2 && b >= a && b >= c) || (b > 0 && (endA == 2 || endC == 2))) {
                res.push_back('b');
                endB++;
                endA = 0;
                endC = 0;
                b--;
            } else if ((endC != 2 && c >= a && c >= b) || (c > 0 && (endA == 2 || endB == 2))) {
                res.push_back('c');
                endC++;
                
                endA = 0;
                endB = 0;
                c--;
            } else {
                break;
            }
        }
        return res;
    }
};