#include "../header.h"

class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        while (num) {
          steps++;
          if (num & 1) {
            num = num - 1;
          } else {
            num = num / 2;
          }
          
        } 
        return steps;
    }
};