#include "../header.h"

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

extern int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n, m = l + (r - l) / 2;
        int res = guess(m);
        while (res != 0 && l < r) {
            if (res == -1) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            m = l + (r - l) / 2;
            res = guess(m);
        }
        return m;
    }
};