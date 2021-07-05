#include "../header.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        int i = 0;
        int one = 1;
        while (i < n) {
            for (int j = res.size() - 1; j >= 0; --j) {
                int temp = res[j] + one;
                res.push_back(temp);
            }
            one <<= 1;            
            ++i;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    auto res = Solution().grayCode(n);
    print_vector<int>(res);
    return 0;
}