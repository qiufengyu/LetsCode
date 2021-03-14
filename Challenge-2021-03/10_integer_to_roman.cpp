#include "../header.h"

class Solution {
    map<int, string> m3;
    map<int, string> m2;
    map<int, string> m1;
public:
    Solution() {
        m1.emplace(0, "");
        m1.emplace(1, "I");
        m1.emplace(2, "II");
        m1.emplace(3, "III");
        m1.emplace(4, "IV");
        m1.emplace(5, "V");
        m1.emplace(6, "VI");
        m1.emplace(7, "VII");
        m1.emplace(8, "VIII");
        m1.emplace(9, "IX");
        m2.emplace(0, "");
        m2.emplace(1, "X");
        m2.emplace(2, "XX");
        m2.emplace(3, "XXX");
        m2.emplace(4, "XL");
        m2.emplace(5, "L");
        m2.emplace(6, "LX");
        m2.emplace(7, "LXX");
        m2.emplace(8, "LXXX");
        m2.emplace(9, "XC");
        m3.emplace(0, "");
        m3.emplace(1, "C");
        m3.emplace(2, "CC");
        m3.emplace(3, "CCC");
        m3.emplace(4, "CD");
        m3.emplace(5, "D");
        m3.emplace(6, "DC");
        m3.emplace(7, "DCC");
        m3.emplace(8, "DCCC");
        m3.emplace(9, "CM");
    }
    string intToRoman(int num) {
        string s = "";
        while (num > 999) {
            s.push_back('M');
            num -= 1000;
        }
        int n3 = num / 100;
        int n2 = (num % 100) / 10;
        int n1 = num % 10;
        s += m3[n3];
        s += m2[n2];
        s += m1[n1];
        return s;
    }
};

int main() {
    int num = 0;
    cin >> num;
    cout << Solution().intToRoman(num) << endl;
    return 0;
}