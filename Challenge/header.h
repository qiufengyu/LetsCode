#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
<<<<<<< HEAD
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

=======
#include <set>
#include <map>
#include <algorithm>
>>>>>>> 74fd9c35f7a88bc5732bb998b0dec04c5131d530
#include "linked_list.h"
#include "binary_tree.h"

using namespace std;

void print_vector(vector<vector<int>>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        cout << "[";
        for(int j = 0; j < v[i].size() - 1; j++) {
            cout << v[i][j] << ", ";
        }
        cout << v[i][v[i].size() - 1];
        cout << "],";
    }
    cout << "]"<<endl;
}