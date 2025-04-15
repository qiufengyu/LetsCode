#include "../header.h"

inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
    long long atLeastK(const string& word, int k) {
        int n = word.size();
        long long res = 0LL;
        int consonants = 0;
        int left = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) {
            if (isVowel(word[right])) {
                mp[word[right]]++;
            } else {
                consonants++;
            }
            while (mp.size() == 5 && consonants >= k) {
                res += (n - right);
                if (isVowel(word[left])) {
                    mp[word[left]]--;
                    if (mp[word[left]] == 0) {
                        mp.erase(word[left]);
                    }
                } else {
                    consonants--;
                }
                left++;
            }
        }
        return res;
    }

public:
    long long countOfSubstrings(string word, int k) {        
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};