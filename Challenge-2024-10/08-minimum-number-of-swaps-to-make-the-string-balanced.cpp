#include "../header.h"

class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = s.size() - 1, res = 0;
        int open = 0, close = 0;
        int i = 0;
        while (i < s.size() - 1) {
            if (s[i] == '[') {
                open++;
            } else {
                close++;
                if (close > open) {
                    while (right > i && s[right] == ']') {
                        right--;
                    }
                    swap(s[i], s[right]);
                    res++;
                    close--;
                    open++;             
                }
            }
            i++;            
        }
        return res;
    }
};