#include "header.h"

class Solution {
public:
    string longestDupSubstring(string S) {
        int N = S.size();
        int l = 0, r = N;
        const long MOD = 1e9+7;
        const int BASE = 256;
        int mid = l + (r - l) / 2;
        int ansLen = 0, ansIndex = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            unordered_map<int, vector<int>> umap;
            // all sustring length = mid
            long long ph = 0L;
            long long h = 0L;
            for (int i = 0; i < mid; i++) {
                if (ph == 0L) {
                    ph = 1L;
                } else {
                    ph = (ph * BASE) % MOD;
                }
                if (h == 0L) {
                    h = S[i];
                } else {
                    h = ((h * BASE % MOD) + S[i]) % MOD;
                }
            }
            // first value
            // cout << S.substr(0, mid) << ": " << h << endl;
            auto &p = umap[h];
            p.push_back(0);
            bool find = false;
            int successIndex = 0;
            for (int j = 1; j + mid <= N; j++) {
                // cout << S.substr(j - 1, mid) << "-" << S[j-1]  << "+" << S[j+mid-1] << endl;
                h = ((((h - S[j-1] * ph) * BASE) % MOD + MOD) % MOD + S[j + mid - 1]) % MOD;
                // cout << S.substr(j, mid) << ": " << h << endl;
                auto &p = umap[h];
                for (int i = 0; i < p.size(); i++) {
                    if (check(S, p[i], j, mid)) {
                        find = true;
                        successIndex = j;
                        break;
                    }
                }
                if (find) {
                    break;
                }
                p.push_back(j);
            }
            if (find) {
                ansLen = mid;
                ansIndex = successIndex;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ansLen == 0) {
            return "";
        }
        return S.substr(ansIndex, ansLen);        

    }

    bool check(string& S, int i, int j, int len) {
        for (int x = 0; x < len; x++) {
            if (S[i+x] != S[j+x]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    // long long h = 0;
    // const int MOD = 101;
    // const int BASE = 256;
    // long long ph = 0L;
    // for (int i = 0; i < 3; i++) {
    //     if (ph == 0) {
    //         ph = 1L;
    //     } else {
    //         ph = ph * BASE % MOD;
    //     }
    //     h = ((h * BASE % MOD) + (s[i])) % MOD;
    // }
    // cout << h << endl;
    // // a(bra)
    // h = (((h - 'a' * ph) * BASE) % MOD + 'a') % MOD;
    // cout << h << endl;
    cout << Solution().longestDupSubstring(s) << endl;
    return 0;
}