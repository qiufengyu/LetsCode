#include "../header.h"
#include <random>


const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

class Solution {
    unordered_map<string, string> long2Tiny;
    unordered_map<string, string> tiny2Long;
    default_random_engine e;
    uniform_int_distribution<unsigned> u;
public:
    Solution(): u(0, 61) {}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string t = "";
        for (int i = 0; i < 6; ++i) {
            t.push_back(alphabet[u(e)]);
        }
        long2Tiny[longUrl] = t;
        tiny2Long[t] = longUrl;
        return "http://tinyurl.com/" + t;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tiny2Long[shortUrl.substr(19)];
    }
};