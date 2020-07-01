#include "header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        vector<char> c {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string res = "";
        int q = 0;
        k = k - 1;
        for (int i = 1; i <= n; i++) {
            q = k / f[n-i];
            res.push_back(c[q]);
            c.erase(c.begin() + q);
            k = k % f[n-i];
        }
        return res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    cout << Solution().getPermutation(n, k) << endl;
}