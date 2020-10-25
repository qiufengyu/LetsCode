#include "../header.h"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int start = 0, end = tokens.size() - 1;
        int res = 0;
        int ans = 0;
        while (start <= end) {
            if (P >= tokens[start]) {
                P -= tokens[start];
                res++;
                start++;
            } else if (res > 0) {
                res--;
                P += tokens[end];
                end--;
            } else {
                break;
            }
            ans = max(ans, res);         
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    int p;
    cin >> p;
    vector<int> tokens = stringToIntegerVector(s);
    cout << Solution().bagOfTokensScore(tokens, p) << endl;
    return 0;
}