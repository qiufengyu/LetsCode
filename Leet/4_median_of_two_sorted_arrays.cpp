//
// Created by Godfray on 2018/3/8.
//

#include <iostream>

#include <string>
#include <sstream>

#include <algorithm>
#include <vector>

using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make nums2 longer than nums1
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int i_min = 0;
        int i_max = m;
        // rounding division
        // i.e. if m+n is odd, plus 1 o/w (m+n)/2
        int half_length = (m+n+1)/2;
        int i = m / 2;
        int j = half_length - i;
        while (i_min <= i_max) {
            // 2 common unfit situations
            if(i < m && nums2[j-1] > nums1[i]) {
                // i is too small
                i_min = i + 1;
            }
            else if(i > 0 && nums1[i-1] > nums2[j]) {
                // i is too big
                i_max = i - 1;
            }
            else {
                // perfect i
                int max_of_left = 0;
                // edge conditions
                if (i == 0) {
                    max_of_left = nums2[j-1];
                }
                else if (j == 0) {
                    max_of_left = nums1[i-1];
                }
                else {
                    max_of_left = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
                }
                // total odd numbers
                if ((m + n) % 2 == 1) {
                    return (double)max_of_left;
                }

                // total even numbers, return average of min_of_right and max_of_left
                int min_of_right = 0;
                if (i == m) {
                    min_of_right = nums2[j];
                }
                else if (j == n) {
                    min_of_right = nums1[i];
                }
                else {
                    min_of_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                }
                return (double)(max_of_left + min_of_right) / 2.0;
            }

            i = (i_max + i_min) / 2;
            j = half_length - i;
        }

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}