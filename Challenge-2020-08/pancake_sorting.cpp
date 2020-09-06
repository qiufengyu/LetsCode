#include "../header.h"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int sz = A.size();
        vector<int> res;
        for (int i = sz; i >= 1; i--) {
            int j = 0;
            while (j < i && A[j] != i) {
                j++;
            }
            if (j == i - 1) continue;
            flip(A, j+1, res);
            flip(A, i, res);
        }
        return res;
    }

    void flip(vector<int>& A, int pos, vector<int>& res) {
        res.push_back(pos);
        reverse(A.begin(), A.begin() + pos);
        cout << "[";
        for (auto x: A) cout << x << ",";
        cout << "]" << endl;
    }
};

int main() {
    string a;
    cin >> a;
    vector<int> A = stringToIntegerVector(a);
    for (auto x: Solution().pancakeSort(A)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}