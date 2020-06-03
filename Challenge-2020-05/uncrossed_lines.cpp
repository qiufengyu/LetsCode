#include "header.h"

// i.e. Longest common sequence
class Solution {
private:
    void print(vector<vector<int>> v) {
        cout << "[" << endl;
        for (auto& v1: v) {
            cout << "[";
            for (auto x: v1) {
                cout << x << " ";
            }
            cout << "],\n";
        }
        cout << "]" << endl;
    }
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int sA = A.size(), sB = B.size();
        if (sA == 0 || sB == 0) {
            return 0;
        }
        vector<vector<int>> res (sA + 1, vector<int> (sB + 1, 0));
        for (int i = sA - 1; i >= 0; i--) {
            int maxLatter = res[i+1][sB];
            int maxLineI = res[i][sB];
            for (int j = sB - 1; j >= 0; j--) {
                maxLatter = maxLatter > res[i+1][j+1] ? maxLatter : res[i+1][j+1];
                if (A[i] == B[j]) {
                    res[i][j] = maxLatter + 1;
                } else {
                    res[i][j] = maxLatter > res[i+1][j] ? maxLatter : res[i+1][j];
                }
                if (maxLineI > res[i][j]) { 
                    res[i][j] = maxLineI;
                } else {
                    maxLineI = res[i][j];
                }
                print(res);
            }
        }
        return res[0][0];
    }
};

int main() {
    vector<int> A {2,5,1,2,5};
    vector<int> B {10,5,2,1,5,2};
    cout << Solution().maxUncrossedLines(A, B) << endl;
}