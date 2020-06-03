//
// Created by Godfray on 2018/3/12.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout<<slow<<", "<<fast<<endl;
        }
        int entry = 0;
        while(entry != slow) {
            slow = nums[slow];
            entry = nums[entry];
            cout<<slow<<", "<<entry<<endl;
        }
        return entry;
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

        int ret = Solution().findDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}


