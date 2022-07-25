#include "../header.h"

void print_queue(queue<string>& q) {
    int sz = q.size();
    if (sz == 0) {
        cout << "Empty" << endl;
    } else {
        while (sz > 0) {
            string s = q.front();
            cout << s << ", ";
            q.pop();
            q.push(s);
            --sz;
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<string>> waiting(26);
        int res = 0;
        for (string const& w: words) {
            int i = w[0] - 'a';
            waiting[i].push(w);
        }
        for (char const& c: s) {
            int sz = waiting[c-'a'].size();
            while (sz > 0) {
                string t = waiting[c-'a'].front();
                if (t.size() == 1) {
                    ++res;
                } else {
                    char newHead = t[1];
                    waiting[newHead-'a'].push(t.substr(1));
                }
                waiting[c-'a'].pop();
                --sz;
            }
        }
        return res;
    }
};

int main() {
    string s = "dsahjpjauf";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << Solution().numMatchingSubseq(s, words) << endl;
    return 0;
}