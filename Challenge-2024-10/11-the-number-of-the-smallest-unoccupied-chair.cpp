#include "../header.h"

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        auto time = times[targetFriend];
        sort(times.begin(), times.end());
        print_vector<int>(times);
        map<int, int> mp;
        int res = -1;
        for (int i = 0; i < times.size(); i++) {
            int a = times[i][0], l = times[i][1];
            bool replace = false;
            for (auto const& p: mp) {
                if (p.second <= a) {
                    mp[p.first] = l;
                    replace = true;
                    res = p.first;
                    break;
                }
            }
            if (time[0] == a && replace) {
                return res;
            }
            if (!replace) {
                res = mp.size();
                mp[mp.size()] = l;
                if (time[0] == a) {
                    return res;
                }
            }            
        }
        return res;
    }
};

int main() {
    vector<vector<int>> times = {{4,5},{12,13},{5,6},{1,2},{8,9},{9,10},{6,7},{3,4},{7,8},{13,14},{15,16},{14,15},{10,11},{11,12},{2,3},{16,17}};
    int target = 15;
    cout << Solution().smallestChair(times, target) << endl;
    return 0;
}