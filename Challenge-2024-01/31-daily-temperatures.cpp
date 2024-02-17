#include "../header.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break;
                } else if (res[j] != 0) {
                    j += res[j];
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> t{73,74,75,71,69,72,76,73};
    auto res =  Solution().dailyTemperatures(t);
    print_vector<int>(res);
    return 0;
}