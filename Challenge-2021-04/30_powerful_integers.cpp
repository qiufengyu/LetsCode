#include "../header.h"

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        for (int i = 1; i < bound; i *= x) {
          for (int j = 1; j < bound; j *= y) {
            if (i + j <= bound) {
              s.insert(i+j);
            }
            else {
              break;
            }
            if (y == 1) {
              break;
            }
          }
          if (x == 1) {
            break;
          }
        }
        vector<int> res;
        for (auto i: s) {
          res.push_back(i);
        }
        return res;
    }
};