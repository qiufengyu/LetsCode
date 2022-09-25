#include "../header.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, sz = data.size();
        while (i < sz) {
            int n = data[i];
            int r = ones(n);
            if (r == -1 || r == 0) {
                cout << "r == -1 or 0" << endl;
                return false;
            } else if (r == 4) {
                i += 4;
                if (i <= sz && ones(data[i-1]) == 0 & ones(data[i-2]) == 0 && ones(data[i-3]) == 0) {
                    continue;
                } else {
                    cout << "r == 4" << endl;
                    return false;
                }
            } else if (r == 3) {
                i += 3;
                if (i <= sz && ones(data[i-1]) == 0 & ones(data[i-2]) == 0) {
                    continue;
                } else {
                    cout << "r == 3" << endl;
                    return false;
                }
            } else if (r == 2) {
                i += 2;
                if (i <= sz && ones(data[i-1]) == 0) {
                    continue;
                } else {
                    cout << "r == 2" << endl;
                    return false;
                }
            } else if (r == 1) {
                i += 1;
            }
        }
        return true;
    }

    int ones(int number) {
        if (number >= 0xF0 && number <= 0xF7) {
            return 4;
        }
        if (number >= 0xE0 && number <= 0xEF) {
            return 3;
        }
        if (number >= 0xC0 && number <= 0xDF) {
            return 2;
        }
        if (number >= 0 && number <= 0x7F) {
            return 1;
        }
        if (number >= 0x80 && number <= 0xBF) {
            return 0;
        }
        return -1;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().validUtf8(v) << endl;
    return 0;
}