class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjList;
        for (const auto& pair : adjacentPairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }
        int start;
        for (const auto& entry : adjList) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }
        vector<int> result;
        unordered_set<int> visited;
        dfs(start, adjList, visited, result);
        
        return result;
    }

void dfs(int node, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, vector<int>& result) {
        visited.insert(node);
        result.push_back(node);
        
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adjList, visited, result);
            }
        }
    }
};