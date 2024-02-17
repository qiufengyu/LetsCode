#include "../header.h"

class UndergroundSystem {
    unordered_map<int, pair<string, int>> userMap;
    unordered_map<string, pair<double, int>> routeMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        userMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto u = userMap[id];
        string key = u.first + '-' + stationName;
        routeMap[key].first += (double)(t - u.second);
        routeMap[key].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + '-' + endStation;
        auto value = routeMap[key];
        return value.first / value.second;
    }
};