#include "../header.h"

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q(target.begin(), target.end());
        long sum = accumulate(target.begin(), target.end(), 0L);
        while (true) {
          int t = q.top();
          q.pop();
          sum -= t;
          if (t == 1 || sum == 1) {
            return true;
          }
          if (t < sum || sum == 0 || t % sum == 0) {
            return false;
          }
          t %= sum;
          sum += t;
          q.push(t);
        }
        return true;
    }
};