#include "../header.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> s1, s2;
        int n = graph.size();
        queue<int> nodes;
        for (int k = 0; k < n; ++k) {
            if (nodes.empty()) {
                if (s1.count(k) == 0 && s2.count(k) == 0) {
                    nodes.push(k);
                }
            }
            while (!nodes.empty()) {
                int i = nodes.front();
                nodes.pop();
                if (s1.count(i) == 0 && s2.count(i) == 0) {
                    // check all nbrs to s1
                    bool f1 = true, f2 = true;
                    for (int const nbr: graph[i]) {
                        if (s1.count(nbr)) {
                            f1 = false;
                        }
                        if (s2.count(nbr)) {
                            f2 = false;
                        }
                    }
                    if (f1) {
                        s1.insert(i);
                        for (int const nbr: graph[i]) {
                            if (s2.count(nbr) == 0) {
                                s2.insert(nbr);
                                nodes.push(nbr);
                            }                        
                        }
                    } else if (f2) {
                        s2.insert(i);
                        for (int const nbr: graph[i]) {
                            if (s1.count(nbr) == 0) {
                                s1.insert(nbr);
                                nodes.push(nbr);
                            }    
                        }
                    } else {
                        return false;
                    }                
                } else if (s2.count(i) == 0) {
                    s1.insert(i);
                    for (int const nbr: graph[i]) {
                        if (s1.count(nbr)) {
                            return false;
                        }                    
                        if (s2.count(nbr) == 0) {
                            s2.insert(nbr);
                            nodes.push(nbr);
                        }                               
                    }
                } else if (s1.count(i) == 0) {
                    s2.insert(i);
                    for (int const nbr: graph[i]) {
                        if (s2.count(nbr)) {
                            return false;
                        }
                        if (s1.count(nbr) == 0) {
                            s1.insert(nbr);
                            nodes.push(nbr);
                        }
                    }
                }
            }
        }        
        return true;
    }
};