#include "../header.h"

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupId++;
            }
        }
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; i++) {
            itemGraph[i] = {};
        }
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(groupId, 0);
        for (int i = 0; i < groupId; i++) {
            groupGraph[i] = {};
        }

        for (int v = 0; v < n; v++) {
            for (int u: beforeItems[v]) {
                itemGraph[u].push_back(v);
                ++itemIndegree[v];
                if (group[v] != group[u]) {
                    groupGraph[group[u]].push_back(group[v]);
                    ++groupIndegree[group[v]];
                }
            }
        }
        vector<int> itemOrder = topologySort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologySort(groupGraph, groupIndegree);
        if (itemOrder.empty() || groupOrder.empty()) {
            return {};
        }
        unordered_map<int, vector<int>> orderedGroups;
        for (int i: itemOrder){
            orderedGroups[group[i]].push_back(i);
        }
        vector<int> res;
        for (int gi: groupOrder) {
            res.insert(res.end(), orderedGroups[gi].begin(), orderedGroups[gi].end());
        }
        return res;
    }

    vector<int> topologySort(unordered_map<int, vector<int>>& graph, vector<int>& indegree) {
        vector<int> visited;
        stack<int> st;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            visited.push_back(current);
            for (int nbr: graph[current]) {
                --indegree[nbr];
                if (indegree[nbr] == 0) {
                    st.push(nbr);
                }
            }
        }
        if (visited.size() == graph.size()) {
            return visited;
        }
        return {};
    }
};