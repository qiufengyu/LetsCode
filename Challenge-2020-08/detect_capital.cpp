#include "../header.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        char start = word[0];
        bool allCapital = start >= 'A' && start <= 'Z' ;
        bool allNotCapital = !allCapital;
        bool firstCapital = allCapital;
        for(int i = 1; i < word.length(); i++) {
            if (word[i] < 'A' || word[i] > 'Z') {
                allCapital = false;
            } else {
                firstCapital = false;
                allNotCapital = false;
            }
        }        
        return allCapital || firstCapital || allNotCapital;        
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().detectCapitalUse(s) << endl;
    return 0;
}