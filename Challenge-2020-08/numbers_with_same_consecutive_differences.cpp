#include "../header.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        set<int> resSet;
        if (N == 1) {
            return {0,1,2,3,4,5,6,7,8,9};
        }
        for (int i = 0; i < 10; i++) {
            helper(N, K, resSet, i, i, 1);
        }
        vector<int> res;
        int threshold = 1;
        for (int i = 0; i < N - 1; i++) {
            threshold *= 10;
        }
        for (auto x: resSet) {
            if (x >= threshold) {
                res.push_back(x);
            }
        }
        return res;
    }

    void helper(int N, int K, set<int>& res, int number, int digit, int length) {
        if (length == N) {
            res.insert(number);
        } else {
            if (digit + K < 10) {
                helper(N, K, res, number * 10 + (digit + K), digit + K, length + 1);
            }
            if (digit - K >= 0) {
                helper(N, K, res, number * 10 + digit - K, digit - K, length + 1);
            }
        }
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    for(auto x: Solution().numsSameConsecDiff(N, K)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

