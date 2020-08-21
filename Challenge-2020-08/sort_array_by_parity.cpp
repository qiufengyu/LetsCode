#include "../header.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int sz = A.size();
        int i = 0, j = sz - 1;
        while (i < j) {
            while (i < sz && A[i] % 2 == 0) i++;
            while (j >= 0 && A[j] % 2 != 0) j--;
            if (i < j) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;        
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> A = stringToIntegerVector(s);
    vector<int> res = Solution().sortArrayByParity(A);
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}