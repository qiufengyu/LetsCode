#include "../header.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int length = secret.length();
        int bulls = 0;
        multiset<char> s, g;
        for (int i = 0; i < length; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                s.insert(secret[i]);
                g.insert(guess[i]);
            }
        }
        int cows = 0;
        for (auto c: s) {
            auto gi = g.find(c);
            if (gi != g.end()) {
                g.erase(gi);
                cows++;
            }
        }
        stringstream ss;
        ss << bulls << "A" << cows << "B";
        return ss.str();
    }
};

int main() {
    string secret, guess;
    cin >> secret >> guess;
    cout << Solution().getHint(secret, guess) << endl;
    return 0;
}