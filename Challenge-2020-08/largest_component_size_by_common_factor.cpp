#include "../header.h"

class Solution {
private:
    vector<int> _mem;
    void unionSet(int x, int y) {
        x = findSet(x);
        y = findSet(y);
        if (x != y) {
            _mem[y] = x;
        }
    }
    int findSet(int x) {
        if (x == _mem[x]) {
            return x;
        }
        return _mem[x] = findSet(_mem[x]);
    }

public:
    Solution(): _mem(100001, 0) {
        for (int i = 0; i < 100001; i++) {
            _mem[i] = i;
        }
    }

    int largestComponentSize(vector<int>& A) {
        int maxElement = *max_element(A.begin(), A.end());
        for (int x: A) {
            int s = sqrt(x);
            for (int i = 2; i <= s; i++) {
                if (x % i == 0) {
                    unionSet(x, i);
                    unionSet(x, x / i);
                }
            }
        }
        unordered_map<int, int> count;
        int ans = 0;
        for (int a: A) {
            int n = ++count[findSet(a)];
            ans = max(ans, n);
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> A = stringToIntegerVector(s);
    cout << Solution().largestComponentSize(A) << endl;
    return 0;
}