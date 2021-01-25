#include "../header.h"

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
          while(st.size() > 0 && st.back() > nums[i] && st.size() + sz - i > k) {
            st.pop_back();
          }
          st.push_back(nums[i]);
          print_vector(st);
        }
        return vector<int>(st.begin(), st.begin() + k);
    }
};

int main() {
  string s;
  cin >> s;
  vector<int> v = stringToIntegerVector(s);
  int n;
  cin >> n;
  auto res = Solution().mostCompetitive(v, n);
  print_vector(res);
  return 0;
}