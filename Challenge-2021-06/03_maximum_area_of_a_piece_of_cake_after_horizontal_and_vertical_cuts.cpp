#include "../header.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      horizontalCuts.push_back(0);
      verticalCuts.push_back(0);
      horizontalCuts.push_back(h);
      verticalCuts.push_back(w);
      sort(horizontalCuts.begin(), horizontalCuts.end());
      sort(verticalCuts.begin(), verticalCuts.end());
      long mh = 0;
      for (int i = 0; i < horizontalCuts.size() - 1; ++i) {
        mh = max(mh, (long)(horizontalCuts[i+1] - horizontalCuts[i]));
      }
      long mw = 0;
      for (int i = 0; i < verticalCuts.size() - 1; ++i) {
        mw = max(mw, (long)(verticalCuts[i+1] - verticalCuts[i]));
      }
      return (mh * mw) % 1000000007;    
    }
};