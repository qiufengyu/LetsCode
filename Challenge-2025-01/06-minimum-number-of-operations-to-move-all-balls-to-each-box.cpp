#include "../header.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);
        vector<int> left(boxes.size() + 1, 0), right(boxes.size() + 1, 0);
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < boxes.size(); i++) {
            left[i+1] = left[i] + leftCount + (boxes[i] - '0');
            leftCount += (boxes[i] - '0');
            int j = boxes.size() - i - 1;
            right[j] = right[j+1] + rightCount + (boxes[j] - '0');
            rightCount += (boxes[j] - '0');            
        }
        for (int i = 0; i < boxes.size(); i++) {
            res[i] = left[i] + right[i+1];
        }
        return res;
    }
};