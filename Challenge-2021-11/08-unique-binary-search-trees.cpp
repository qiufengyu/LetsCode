#include "../header.h"

class Solution {
public:
    int numTrees(int n) {
        int trees[20];
        memset(trees, 0, sizeof(trees));
        trees[0] = 1;
        trees[1] = 1;
        trees[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                trees[i] += trees[j] * trees[i - j - 1];
            }
        }
        return trees[n];        
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().numTrees(n) << endl;
    return 0;
}