#include "../header.h"

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                visited[leftChild[i]] = true;
            }
            if (rightChild[i] != -1) {
                visited[rightChild[i]] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (startNode == -1) {
                    startNode = i;
                } else {
                    return false;
                }
            }
            // reset the visited array for next check
            visited[i] = false;
        }
        if (startNode != -1) {
            if (dfs(n, leftChild, rightChild, startNode, visited)) {
                for (int i = 0; i < n; i++) {
                    if (!visited[i]) {
                        return false;
                    }
                }
                return true;
            }
        }        
        return false;
    }

    bool dfs(int n, vector<int>& leftChild, vector<int>& rightChild, int node, vector<bool>& visited) {
        if (visited[node]) {
            return false;
        }
        visited[node] = true;
        if (leftChild[node] == -1) {
            if (rightChild[node] != -1) {
                return dfs(n, leftChild, rightChild, rightChild[node], visited);
            }
        } else {
            if (rightChild[node] == -1) {
                return dfs(n, leftChild, rightChild, leftChild[node], visited);
            } else {
                return dfs(n, leftChild, rightChild, leftChild[node], visited) && dfs(n, leftChild, rightChild, rightChild[node], visited);
            }
        }
        return true;
    }
};