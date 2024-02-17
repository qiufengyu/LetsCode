#include "../header.h"

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0, n = garbage.size();
        int g = 0, p = 0, m = 0;
        for (int i = 0; i < n; i++) {
            res += garbage[i].size();
            if (garbage[i].find('G') != string::npos) {
                g = i;
            }
            if (garbage[i].find('M') != string::npos) {
                m = i;
            }
            if (garbage[i].find('P') != string::npos) {
                p = i;
            }
        }
        cout << res << endl;
        for (int i = 0; i < n - 1; i++) {
            if (g > i) {
                res += travel[i];
                cout << "+g" << travel[i] << endl;
            }
            if (m > i) {
                res += travel[i];
                cout << "+m" << travel[i] << endl;
            }
            if (p > i) {
                res += travel[i];
                cout << "+p" << travel[i] << endl;
            }
        }
        return res;
    }
};

int main() {
    vector<string> garbage {"G","P","GP","GG"};
    vector<int> travel {2,4,3};
    cout << Solution().garbageCollection(garbage, travel) << endl;
    return 0;
}