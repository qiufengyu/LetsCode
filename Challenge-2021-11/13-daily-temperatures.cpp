#include "../header.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t sz = temperatures.size();
        vector<int> res(sz, 0);
        for (int i = sz - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < sz && temperatures[i] >= temperatures[j]) {
                if (res[j] == 0) {
                    break;
                }
                j += res[j];
            }
            if (j < sz) {
                res[i] = temperatures[j] > temperatures[i] ? j - i : 0;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    auto res = Solution().dailyTemperatures(v);
    print_vector<int>(res);
    return 0;
}