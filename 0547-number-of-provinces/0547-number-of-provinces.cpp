class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Create the adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); // because it's an undirected graph
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        // Use DFS to count connected components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;  
    }
};