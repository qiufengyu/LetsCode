#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> m;
        sort(arr.begin(), arr.end());
        for (int const& x: arr) {
            m[x] = 1;
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < i && arr[j] <= sqrt(arr[i]); ++j) {
                int q = arr[i] / arr[j];
                if (arr[i] % arr[j] == 0 && m.count(q) != 0) {
                    m[arr[i]] += (m[arr[j]] * m[q]);
                    m[arr[i]] %= M;
                    if (arr[j] != q) {
                        m[arr[i]] += (m[arr[j]] * m[q]);
                        m[arr[i]] %= M;                        
                    }
                }
            }
        }
        int res = 0;
        for (auto const& p: m) {
            res += p.second;
            res %= M;
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> arr = stringToIntegerVector(s);
    cout << Solution().numFactoredBinaryTrees(arr) << endl;
    return 0;
}