#include "../header.h"

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    virtual int get(int index) {return -1;}
    virtual int length() {return -1;}
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = findPeak(mountainArr, 0, n - 1, n);
        int lr = search(mountainArr, 0, peakIndex, target, true);
        if (mountainArr.get(lr) == target) {
            return lr;
        }
        int rr = search(mountainArr, peakIndex + 1, n - 1, target, false);
        if (mountainArr.get(rr) == target) {
            return rr;
        }
        return -1;
    }

    int search(MountainArray& mountainArr, int l, int r, int target, bool b) {
        while (l < r) {
            int m = l + (r - l) / 2;
            int cand = mountainArr.get(m);
            if (b) {                
                if (cand < target) {
                    l = m + 1;
                } else if (cand > target){
                    r = m - 1;
                } else {
                    return m;
                }
            } else {
                if (cand > target) {
                    l = m + 1;
                } else if (cand < target){
                    r = m - 1;
                } else {
                    return m;
                }
            }
        }
        return l;
    }

    int findPeak(MountainArray& mountainArr, int l, int r, int n) {
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m < n - 1 && mountainArr.get(m) < mountainArr.get(m+1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};