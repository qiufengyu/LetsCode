#include "../header.h"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
        return a[1] > b[1];
      });
      print_vector(boxTypes);
      int currentSize = 0;
      int res = 0;
      for (auto const& box: boxTypes) {
        if (currentSize < truckSize) {
          int take = min(truckSize - currentSize, box[0]);
          currentSize += take;
          res += box[1] * take;
        } else {
          break;
        }
      }
      return res;        
    }
};

int main() {
  vector<vector<int>> boxTypes {{5,10},{2,5},{4,7},{3,9}};
  int truckSize = 10;
  cout << Solution().maximumUnits(boxTypes, truckSize) << endl;
  return 0;
}