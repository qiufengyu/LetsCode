#include "../header.h"

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> generator {1,2,3,4,5,6,7,8,9};
        vector<int> res;
        bool flag = true;
        int start = 0;
        while (flag) {
            flag = false;
            int sz = generator.size();
            for (int i = start; i < sz; ++i) {
                // no need to generate
                if (generator[i] > high) {
                    break;
                }
                int n = generateNext(generator[i]);
                if (n > 0) {
                    generator.push_back(n);
                    flag = true;
                    if (n >= low && n <= high) {
                        res.push_back(n);
                    }
                }
            }
            start = sz;
        }
        sort(res.begin(), res.end());
        return res;
    }

    int generateNext(int number) {
        int d = number % 10;
        if (d == 9) {
            return -1;
        }
        return (number * 10 + d + 1);
    }
};

int main() {
    int low, high;
    cin >> low >> high;
    vector<int> res = Solution().sequentialDigits(low, high);
    print_vector<int>(res);
    return 0;

}