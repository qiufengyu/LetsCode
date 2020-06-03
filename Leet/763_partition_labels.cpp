//
// Created by Fengyu Qiu on 2018/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> m;
        for(int i = 0; i<S.length(); ++i) {
            m[S[i]] = i;
        }
        int i = 0;
        vector<int> res;
        while(i < S.length()) {
            int end = m[S[i]];
            for(int j = i; j<end; ++j) {
                if(m[S[j]] > end) {
                    end = m[S[j]];
                }
            }
            res.push_back(end-i+1);
            i = end + 1;
        }
        return res;

    }
};

int main() {
    vector<int> res = Solution().partitionLabels("ababcbacadefegdehijhklij");
    for(auto x: res) {
        cout<< x <<"\n";
    }
    return 0;
}
