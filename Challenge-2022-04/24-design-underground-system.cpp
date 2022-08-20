#include "../header.h"

class UndergroundSystem {
    unordered_map<int, pair<string, int>> inMap;
    unordered_map<string, pair<double, int>> routeMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto in = inMap[id];
        string k = in.first + '-' + stationName;
        routeMap[k].first += (t - in.second);
        routeMap[k].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string k = startStation + '-' + endStation;
        auto route = routeMap[k];
        return route.first / route.second;
    }
};