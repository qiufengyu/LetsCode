#include "../header.h"

class NumArray {
    int n;
    vector<int> rs;
    vector<int> _m;
public:
    NumArray(vector<int>& nums): n(nums.size()), _m(nums.begin(), nums.end()) {
        int x = (int)ceil(log(n) / log(2));
        int maxSize = 2 * pow(2, x) - 1;
        rs.resize(maxSize, 0);
        constructSegmentTree(nums, 0, n - 1, 0);
    }

    int constructSegmentTree(vector<int>& nums, int start, int end, int rsIndex) {
        if (start == end) {
            rs[rsIndex] = nums[start];
            return rs[rsIndex];
        }
        int mid = start + (end - start) / 2;
        rs[rsIndex] = constructSegmentTree(nums, start, mid, rsIndex * 2 + 1) + constructSegmentTree(nums, mid + 1, end, rsIndex * 2 + 2);
        return rs[rsIndex];
    }
    
    void update(int index, int val) {
        int diff = val - _m[index];
        _m[index] = val;
        updateUtil(0, n - 1, index, diff, 0);
    }

    void updateUtil(int start, int end, int index, int diff, int rsIndex) {
        if (index < start || index > end) {
            return;
        }
        rs[rsIndex] = rs[rsIndex] + diff;
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateUtil(start, mid, index, diff, 2 * rsIndex + 1);
            updateUtil(mid + 1, end, index, diff, 2 * rsIndex + 2);
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeUtil(0, n - 1, left, right, 0);
    }

    int sumRangeUtil(int start, int end, int left, int right, int rsIndex) {
        if (left <= start && right >= end) {
            return rs[rsIndex];
        }
        if (left > end || right < start) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        return sumRangeUtil(start, mid, left, right, 2 * rsIndex + 1) + sumRangeUtil(mid + 1, end, left, right, 2 * rsIndex + 2);
    }
};