#include "../header.h"

struct FCR {
    string food;
    string cuisine;
    int rating;
    FCR() = default;
    FCR(string f, string c, int r): food{f}, cuisine{c}, rating{r} {}
    bool operator<(const FCR& a) const {
        if (rating == a.rating) {
            return food < a.food;
        }
        return rating > a.rating;
    }
};

class FoodRatings {
    unordered_map<string, FCR> food2FCR;
    unordered_map<string, set<FCR>> cuisine2FCR;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food2FCR[foods[i]] = FCR(foods[i], cuisines[i], ratings[i]);
            cuisine2FCR[cuisines[i]].insert(FCR(foods[i], cuisines[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        FCR& fcr = food2FCR[food];
        cuisine2FCR[fcr.cuisine].erase(fcr);
        fcr.rating = newRating;
        cuisine2FCR[fcr.cuisine].insert(fcr);
    }
    
    string highestRated(string cuisine) {
        return cuisine2FCR[cuisine].begin()->food;
    }
};