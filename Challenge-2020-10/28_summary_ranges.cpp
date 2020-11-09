#include "../header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() > 1) {
            int start = 0, end;
            long counter;
            stringstream ss;
            while (start < nums.size()) {
                counter = nums[start] + 1L;
                end = start + 1;
                while (end < nums.size()) {
                    if (counter == (long)nums[end]) {
                        end++;
                        counter++;
                    } else {
                        break;
                    }
                }
                if (end == start + 1) {
                    ss << nums[start];
                    res.push_back(ss.str());
                } else {
                    ss << nums[start] << "->" << nums[end - 1];
                    res.push_back(ss.str());
                }
                start = end;
                ss.str(std::string());
                ss.clear();
            }
        } else if (nums.size() == 1) {
            stringstream ss;
            ss << nums[0];
            res.push_back(ss.str());
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    vector<string> res = Solution().summaryRanges(v);
    print_vector<string>(res);
    return 0;
}