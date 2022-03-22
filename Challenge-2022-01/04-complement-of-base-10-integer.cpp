#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int mask = 0;
        int temp = n;
        while (temp != 0) {
            mask = mask * 2 + 1;
            temp = temp >> 1;
        }
        return (mask & (~n));        
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().bitwiseComplement(n) << endl;
    return 0;
}