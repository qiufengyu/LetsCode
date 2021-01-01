#include "../header.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int m = arr.size(), n = pieces.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
          index[pieces[i][0]] = i;
        }
        int i = 0, current = -1;
        while (i < m) {
          current = arr[i];
          if (index.count(current) == 0) {
            return false;
          }
          vector<int> v = pieces[index[current]];
          for (int j = 0; j < v.size(); j++) {
            if (arr[i] != v[j]) {
              return false;
            }
            i++;
          }
        }
        return true;
    }
};