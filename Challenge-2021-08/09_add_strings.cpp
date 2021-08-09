#include "../header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int mx = max(n1, n2);
        string res(mx + 1, '0');
        if (n1 > n2) {
            int flag = 0;
            int i = 0;
            while (i < n2) {
                int t = (num2[n2 - 1 - i] - '0') + (num1[n1 - 1 - i] - '0')  + flag;
                flag = t / 10;
                t %= 10;
                res[mx - i] = '0' + t;
                i++;
            }
            while (i < n1) {
                int t = (num1[n1 - 1 - i] - '0') + flag;
                flag = t / 10;
                t %= 10;
                res[mx - i] = '0' + t;
                i++;
            }
            if (flag == 1) {
                res[0] = '1';
                return res;
            } else {
                return res.substr(1);
            }
        } else {
            int flag = 0;
            int i = 0;
            while (i < n1) {
                int t = (num2[n2 - 1 - i] - '0') + (num1[n1 - 1 - i] - '0')  + flag;                
                flag = t / 10;
                t %= 10;
                res[mx - i] = '0' + t;
                i++;
            }
            while (i < n2) {
                int t = (num2[n2 - 1 - i] - '0') + flag;
                flag = t / 10;
                t %= 10;
                res[mx - i] = '0' + t;
                i++;
            }
            if (flag == 1) {
                res[0] = '1';
                return res;
            } else {
                return res.substr(1);
            }
        }
    }
};

int main() {
    string n1, n2;
    cin >> n1 >> n2;
    cout << Solution().addStrings(n1, n2) << endl;
    return 0;
}