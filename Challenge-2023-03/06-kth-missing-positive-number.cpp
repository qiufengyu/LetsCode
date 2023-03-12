#include "../header.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int mx = arr[n-1] + k;
        int res = 1;
        for (int i = 0; i < n && k > 0; ++i) {
            cout << "arr[i] " << arr[i] << endl;
            if (arr[i] != res) {
                --k;
                --i;
                cout << "k = " << k << endl;
            }
            ++res;
        }
        return res + k - 1;
    }
};

int main() {
    vector<int> arr{2,3,4,7,11};
    int k = 5;
    cout << Solution().findKthPositive(arr, k) << endl;
    return 0;
}