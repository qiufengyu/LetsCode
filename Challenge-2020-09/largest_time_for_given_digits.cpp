#include "../header.h"

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        char h1, h2, m1, m2;
        string res;
        const string _h {"23"};
        const string _m {"59"};
        while (true) {
            h1 = A[0] + '0';
            h2 = A[1] + '0';
            m1 = A[2] + '0';
            m2 = A[3] + '0';
            string h {h1, h2};
            string m {m1, m2};
            if (h.compare(_h) <= 0 && m.compare(_m) <= 0) {
                res = h + ":" + m;
            }
            if (!next_permutation(A.begin(), A.end())) {
                break;
            }
        }
        return res;
        
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> A = stringToIntegerVector(s);
    cout << Solution().largestTimeFromDigits(A) << endl;
    return 0;
}