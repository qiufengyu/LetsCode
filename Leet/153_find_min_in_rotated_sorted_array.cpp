//
// Created by Godfray on 2018/3/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) {
            return nums[0];
        }
        int left = 0, right = length-1;
        while(left < right) {
            // mid < right
            int mid = left + (right-left) / 2;
            cout<<"left = " << nums[left] << ", mid = " << nums[mid] << ", right = "<< nums[right]<<endl;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if(nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return nums[left];
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}