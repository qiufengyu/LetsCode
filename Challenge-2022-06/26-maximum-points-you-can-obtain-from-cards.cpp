#include "../header.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int l = cardPoints.size() - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + l, 0);
        int mn = sum;
        for (int i = l; i < cardPoints.size(); ++i) {
            sum = sum + cardPoints[i] - cardPoints[i-l];            
            mn = min(mn, sum);
        }
        return total - mn;      
    }
};