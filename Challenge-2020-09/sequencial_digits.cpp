#include "../header.h"

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> digits;
        for (int i = 1; i < 10; i++) {
            digits.push(i);
        };
        vector<int> res;
        while (digits.size() > 0) {
            int number = digits.front();
            digits.pop();
            if (number >= low && number <= high) {
                res.push_back(number);
            } else if (number > high) {
                break;
            }
            int last = number % 10;
            if (last < 9) {
                int newValue = number * 10 + last + 1;
                digits.push(newValue);
            }
        }
        // sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    int l, h;
    cin >> l >> h;
    auto res = Solution().sequentialDigits(l, h);
    print_vector(res);
    return 0;
}