#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        long e = nums.size();
        if (e == 1) {
            return nums[0];
        }
        long s = 0;
        long m = (e + s) / 2;
        while (e > s) {
            if (m % 2 == 0) {
                if (nums[m] == nums[m+1]) {
                    s = m;
                }
                else {
                    e = m;
                }
            } else {
                if (nums[m] == nums[m+1]) {
                    e = m - 1;
                }
                else {
                    s = m + 1;
                }                
            }
            m = (e + s) / 2;
            // cout << s << ", " << m << ", " << e << endl;
        }
        return nums[m];        
    }
};

int main() {
    vector<int> v {1,1,3};
    cout << (new Solution())->singleNonDuplicate(v) << endl;
}