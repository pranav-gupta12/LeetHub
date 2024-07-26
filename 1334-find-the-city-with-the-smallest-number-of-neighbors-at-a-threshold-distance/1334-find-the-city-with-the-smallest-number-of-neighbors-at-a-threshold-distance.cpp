class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances based on edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        // Set the distance from a node to itself to 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find all pairs shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distance threshold
        int minReachableCities = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities < minReachableCities) {
                minReachableCities = reachableCities;
                resultCity = i;
            } else if (reachableCities == minReachableCities) {
                resultCity = i; // Tie-breaking: choose the city with the greatest index
            }
        }

        return resultCity;
    }
};