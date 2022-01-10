#include "../header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int ai = a.length() - 1, bi = b.length() - 1;
        string res = "";
        int flag = 0;
        while (ai >=0 && bi >= 0) {
            int temp = (a[ai] - '0') + (b[bi] - '0') + flag;
            flag = temp / 2;
            temp = temp % 2;
            if (temp == 0) {
                res = "0" + res;
            } else {
                res = "1" + res;
            }
            --ai;
            --bi;
        }
        while (ai >= 0) {
            int temp = (a[ai] - '0') + flag;
            flag = temp / 2;
            temp = temp % 2;
            if (temp == 0) {
                res = "0" + res;
            } else {
                res = "1" + res;
            }
            --ai;
        }
        while (bi >= 0) {
            int temp = (b[bi] - '0') + flag;
            flag = temp / 2;
            temp = temp % 2;
            if (temp == 0) {
                res = "0" + res;
            } else {
                res = "1" + res;
            }
            --bi;
        }
        if (flag == 1) {
            res = "1" + res;
        }
        return res;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    cout << Solution().addBinary(a, b) << endl;
    return 0;
}