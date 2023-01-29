#ifndef HEADER_H
#define HEADER_H

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "linked_list.h"
#include "binary_tree.h"

using std::vector;

template<class T>
void print_vector(vector<T>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size() - 1; i++) {
        cout << v[i] << ",";
    }
    if (v.size() > 0) {
        cout << v[v.size() - 1];
    }
    cout << "]" << endl;
}

template<class T>
void print_vector(vector<vector<T>>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        cout << "[";
        for(int j = 0; j < (int)v[i].size() - 1; j++) {
            cout << v[i][j] << ",";
        }
        if (v[i].size() > 0) {
            cout << v[i][v[i].size() - 1];
        }
        if (i == (int)(v.size() - 1)) {
            cout << "]";
        } else {
            cout << "],";
        }
    }
    cout << "]"<< endl;
}


#endif
