#include "../header.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        return helper(mp, groupSize, n);
    }

    bool helper(map<int, int>& mp, int groupSize, int size) {
        if (size == 0) {
            return true;
        }
        int num = 0;
        for (auto const& p: mp) {
            int cnt = p.second;
            num = p.first;
            if (cnt != 0) {
                for (int l = 0; l < groupSize; l++) {
                    mp[num + l] -= cnt;
                    if (mp[num + l] < 0) {
                        return false;
                    }
                }
                break;
            }
        }
        mp.erase(num);
        return helper(mp, groupSize, size - groupSize);
    }
};