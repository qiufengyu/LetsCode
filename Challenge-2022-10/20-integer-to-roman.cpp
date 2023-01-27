#include "../header.h"

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int t = num / 1000;
        while (t > 0) {
            res.push_back('M');
            --t;    
        }
        int h = (num % 1000) / 100;
        if (h == 9) {
            res += "CM";
        } else if (h == 4) {
            res += "CD";
        } else {
            if (h >= 5) {
                h -= 5;
                res += "D";
            }
            while (h > 0) {
                res += "C";
                --h;
            }
        }
        int d = (num % 100) / 10;
        if (d == 9) {
            res += "XC";
        } else if (d == 4) {
            res += "XL";
        } else {
            if (d >= 5) {
                d -= 5;
                res += 'L';
            }
            while (d > 0) {
                res += "X";
                --d;
            }
        }
        int n = num % 10;
        if (n == 9) {
            res += "IX";
        } else if (n == 4) {
            res += "IV";
        } else {
            if (n >= 5) {
                n -= 5;
                res += "V";
            }
            while (n > 0) {
                res += "I";
                --n;
            }
        }
        return res;
    }
};