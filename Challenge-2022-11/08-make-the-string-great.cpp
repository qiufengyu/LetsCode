#include "../header.h"

class Solution {
public:
    string makeGood(string s) {
        string temp = s;
        int i = 0;
        while (temp.size() > 0 && i < temp.size() - 1) {
            if (abs(temp[i] - temp[i+1]) == 32) {
                temp = temp.substr(0, i) + temp.substr(i+2, temp.size() - i - 1);
                i = i - (i == 0 ? 0 : 1);
            } else {
                ++i;
            }
        }        
        return temp;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().makeGood(s) << endl;
    return 0;
}