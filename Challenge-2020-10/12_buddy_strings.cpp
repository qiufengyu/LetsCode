#include "../header.h"

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        int sz = A.length();
        vector<int> diff;
        for (int i = 0; i < sz; i++) {
            if (A[i] != B[i]) {
                diff.push_back(i);
            }
        }
        if (diff.size() == 2) {
            return A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
        } else if (diff.empty()) {
            bool contains[26] = {false};
            for (auto& c: A) {
                if (contains[c - 'a']) {
                    return true;
                } else {
                    contains[c - 'a'] = true;
                }
            }
        }
        return false;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    cout << Solution().buddyStrings(a, b) << endl;
    return 0;
}