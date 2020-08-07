#include "header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int i;   
        for (i = length - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] = digits[i] + 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        if (i == -1 && digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    vector<int> v {9};
    vector<int> r = Solution().plusOne(v);
    for (auto x: r) {
        cout << x << endl;
    }
    return 0;
}