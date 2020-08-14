#include "../header.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r1(rowIndex + 1, 1);
        vector<int> r2(rowIndex + 1, 1);
        int i = 0;
        while (i <= rowIndex) {
            if (i % 2 == 0) {
                // from r1 to r2
                for (int j = 1; j < i; j++) {
                    r2[j] = r1[j-1] + r1[j];
                }
            } else {
                for (int j = 1; j < i; j++) {
                    r1[j] = r2[j-1] + r2[j];
                }
            }
            i++;
        }
        if (rowIndex % 2 == 0) {
            return r2;
        } else {
            return r1;
        }
    }
};

int main() {
    int r;
    cin >> r;
    vector<int> v = Solution().getRow(r);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}