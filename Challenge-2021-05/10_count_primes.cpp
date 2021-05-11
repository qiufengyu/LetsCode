#include "../header.h"

class Solution {
public:
    int countPrimes(int n) {
      if (n == 0 || n == 1) {
        return 0;
      }
      vector<bool> primes(n, true);
      primes[0] = false;
      primes[1] = false;
      for (int i = 2; i * i < n; ++i) {
        if (!primes[i]) {
            continue;
        }
        for (int j = i * i; j < n; j += i) {
          primes[j] = false;
        }
      }
      int res = 0;
      for (int i = 2; i < n; ++i) {
        if (primes[i]) {
          ++res;
        }
      }
      return res;
    }    
};