#include "../header.h"

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] > b[0]) {
                return true;
            }
            if (a[0] < b[0]) {
                return false;
            }
            return a[1] < b[1];
        });
        print_vector<int>(properties);
        int maxDefense = 0;
        for (int i = 0; i < properties.size(); ++i) {
            if (properties[i][1] < maxDefense) {
                ++res;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> p {{1,1},{2,1},{2,2},{1,2}};// {{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
    int res = Solution().numberOfWeakCharacters(p);
    cout << res << endl;
    return 0;
}