#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.size() == 0 || B.size() == 0) {
            return res;
        }
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            vector<int> Ai = A[i];
            vector<int> Bj = B[j];
            if (Ai[1] <= Bj[0]) {
                if (Ai[1] == Bj[0]) {
                    res.push_back({Ai[1], Bj[0]});
                }
                i++;
            } else if (Bj[1] <= Ai[0]) {
                if (Bj[1] == Ai[0]) {
                    res.push_back({Bj[1], Ai[0]});
                }
                j++;
            } else if (Ai[0] <= Bj[0]) {
                if (Bj[1] <= Ai[1]) {
                    res.push_back({Bj[0], Bj[1]});
                    j++;
                } else {
                    res.push_back({{Bj[0], Ai[1]}});
                    i++;
                }
            } else if (Bj[0] <= Ai[0]) {
                if (Ai[1] <= Bj[1]) {
                    res.push_back({Ai[0], Ai[1]});
                    i++;
                } else {
                    res.push_back({Ai[0], Bj[1]});
                    j++;
                }
            }            
        }
        return res;
    }
};

int main() {
    vector<vector<int>> A {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> B {{1,5}, {8,12}, {15,24}, {25,26}};
    vector<vector<int>> res =  Solution().intervalIntersection(A, B);
    for(auto &r: res) {
        cout << r[0] << ", " << r[1] << endl;
    }
    return 0;

}