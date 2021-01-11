#include "../header.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = 0;
        int missingCount = 0;
        for (int i = 0; i < arr.size() && missingCount < k; i++) {
          n++;
          if (arr[i] != n) {
            missingCount++;
            i--; 
          }          
        }
        return missingCount == k ? n : n + (k - missingCount);
    }
};

int main() {
  string s;
  cin >> s;
  vector<int> arr = stringToIntegerVector(s);
  int k;
  cin >> k;
  cout << Solution().findKthPositive(arr, k) << endl;
  return 0;
}