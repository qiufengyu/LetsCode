#include "../header.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        stringstream ss;
        for (int i = 1; i <=n; i++) {            
            if (i % 15 == 0) {
                ss << "FizzBuzz";                
            } else if (i % 5 == 0) {
                ss << "Buzz";
            } else if (i % 3 == 0) {
                ss << "Fizz";
            } else {
                ss << i;
            }
            res.push_back(ss.str());
            ss.str(string());
            ss.clear();
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> r = Solution().fizzBuzz(n);
    for (auto x: r) {
        cout << x << endl;
    }
    return 0;
}

