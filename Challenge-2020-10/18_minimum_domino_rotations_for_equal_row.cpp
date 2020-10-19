#include "../header.h"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int pA = A[0], pB = B[0];
        bool aFlag = true, bFlag = true;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != pA && B[i] != pA) {
                aFlag = false;
            }
            if (A[i] != pB && B[i] != pB) {
                bFlag = false;
            }
        }
        int resA = -1, resB = -1;        
        if (aFlag) {
            int aChange = 0, bChange = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] != pA) {
                    aChange++;
                } else if (B[i] != pA) {
                    bChange++;
                }
            }
            resA = min(aChange, bChange);
        }
        if (bFlag) {
            int aChange = 0, bChange = 0;
            for (int i = 0; i < A.size(); i++) {
                if (B[i] != pB) {
                    aChange++;
                } else if (A[i] != pB) {
                    bChange++;
                }
            }
            resB = min(aChange, bChange);
        }
        if (aFlag && bFlag) {
            return min(resA, resB);
        } else {
            return aFlag ? resA : (bFlag ? resB : -1);
        }
};

int main() {
	return 0;
}
