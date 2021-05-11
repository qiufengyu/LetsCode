#include "../header.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int rest = cardPoints.size() - k;
      int sumStart = accumulate(cardPoints.begin(), cardPoints.begin() + rest, 0);
      int minSum = sumStart;
      int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
      for (int i = rest; i < cardPoints.size(); ++i) {
        sumStart = sumStart - cardPoints[i-rest] + cardPoints[i];
        if (sumStart < minSum) {
          minSum = sumStart;
        }
      }
      return totalSum - minSum;
    }
};