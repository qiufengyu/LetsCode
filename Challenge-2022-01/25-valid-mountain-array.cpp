#include "../header.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool increasing = arr[0] < arr[1], decreasing = false;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (increasing) {
                if (arr[i] > arr[i+1]) {
                    increasing = false;
                    decreasing = true;
                } else if (arr[i] == arr[i+1]) {
                    return false;
                }
            }
            if (decreasing) {
                if (arr[i] <= arr[i+1]) {
                    return false;
                }
            }
        }
        return decreasing;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> arr = stringToIntegerVector(s);
    cout << Solution().validMountainArray(arr) << endl;
    return 0;
}