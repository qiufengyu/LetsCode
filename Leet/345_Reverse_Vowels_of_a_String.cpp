//
// Created by Fengyu Qiu on 2018/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <set>

using namespace std;

class Solution {
private:
    set<char> st;
public:
    Solution() {
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
    }
    string reverseVowels(string s) {
        int start = 0, end = s.length()-1;
        while(start < end) {
            while(start < end && st.find(s[start]) == st.end()) {
                start++;
            }
            while(start < end && st.find(s[end]) == st.end()) {
                end--;
            }
            if(start < end) {
                char t = s[start];
                s[start] = s[end];
                s[end] = t;
                start++;
                end--;
            }
        }
        return s;

    }
};

int main() {
    vector<int> v = {7,6,8,0,4,2,1,5};
    sort(v.begin(), v.end());
    auto res = Solution().reverseVowels("hefasfiotwenltalntjwiwltn");
    cout<<res<<endl;
    return 0;
}
