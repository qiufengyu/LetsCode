#include "../header.h"

const string starting = "http://tinyurl.com/";

class Solution {
    unordered_map<string, string> long2Short, short2Long;
    string _m;
public:
    Solution() {
        _m = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2Long.clear();
        long2Short.clear();
        srand(time(nullptr));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!long2Short.count(longUrl)) {
            int index = 0;
            string randString = "";
            for (int i = 0; i < 6; ++i) {
                randString.push_back(_m[rand() % 62]);
            }
            while (short2Long.count(randString)) {
                randString[index] = _m[rand() % 62];
                index = (index + 1) % 5;
            }
            short2Long[randString] = longUrl;
            long2Short[longUrl] = randString;           
        }        
         return starting + long2Short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randString = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return short2Long.count(randString) ? short2Long[randString] : "";
    }
};