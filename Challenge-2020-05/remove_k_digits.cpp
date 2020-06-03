#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int first_not_zero = num.find_first_not_of('0');
        if (num.find_first_not_of('0') > 0) {
            if (first_not_zero < num.size()) {
                num.erase(num.begin(), num.begin() + first_not_zero);
            } else {
                return "0";
            }
        }
        if (k >= num.size()) {
            return "0";
        } else if (k == 0) {
            return num;
        } else {
            for (int i = 0; i<num.size()-1; ++i) {
                if (num[i] > num[i+1]) {
                    num.erase(num.begin() + i);
                    return removeKdigits(num, k-1);
                }
            }
            num.erase(num.end()-1);
            return removeKdigits(num, k-1);            
        }
    }
};

int main() {
    Solution s;
    string num;
    int k;
    cin >> num >> k;
    string n2 = num.substr(2);
    // cout << n2 << ", "<< n2.find_first_not_of('0') <<endl;
    cout << s.removeKdigits(num, k)<< endl;
    return 0;
}