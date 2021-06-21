#include "../header.h"

class NumArray {
  vector<int> tree;
  size_t length;
public:
    NumArray(vector<int>& nums) {
      length = nums.size();
      tree.resize(2 * length);
      buildTree(nums);      
    }

    void buildTree(vector<int>& nums) {
      for (int i = length, j = 0; i < 2 * length; ++i, ++j) {
        tree[i] = nums[j];
      }
      for (int i = length - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
      }
    }
    
    void update(int index, int val) {
        index += length;
        tree[index] = val;
        while (index > 0) {
          int l = index, r = index;
          if (index % 2 == 0) {
            r = index + 1;
          } else {
            l = index - 1;
          }
          tree[index / 2] = tree[l] + tree[r];
          index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += length;
        right += length;
        int sum = 0;
        while (left <= right) {
          if ((left % 2) == 1) {
            sum += tree[left];
            left++;
          }
          if ((right % 2) == 0) {
            sum += tree[right];
            right--;
          }
          left /= 2;
          right /= 2; 
        }
        return sum;
    }
};
