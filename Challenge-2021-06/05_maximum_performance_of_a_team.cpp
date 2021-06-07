#include "../header.h"

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> members;
        for (int i = 0; i < n; ++i) {
          members.push_back({speed[i], efficiency[i]});
        }
        sort(members.begin(), members.end(), [](const pair<int, int> a, const pair<int, int> b) -> bool {
          return a.second > b.second;
        });
        for (auto const& m: members) {
          cout << m.first << ", " << m.second << endl;
        }
        priority_queue<int, vector<int>, greater<int>> q;
        long sum = 0, res = 0;
        for (int i = 0; i < n; ++i) {
          if (i >= k) {
            sum -= q.top();
            q.pop();
          }
          sum += members[i].first;
          q.push(members[i].first);
          res = max(res, sum * members[i].second);
        }
        return res % 1000000007;
    }
};

int main() {
  int n = 6, k = 3;
  vector<int> speed {2,10,3,1,5,8}, efficiency {5,4,3,9,7,2};
  int res = Solution().maxPerformance(n, speed, efficiency, k);
  cout << res << endl;
  return 0;
}