class Solution {
public:
    typedef pair<int, int> pii; // Pair to store (distance, node)

// Function to perform Dijkstra's algorithm
int dijkstra(int V, vector<vector<pii>>& adj, int src, int distanceThreshold) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    
    pq.push({0, src});
    dist[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
        for (int i = 0; i < V; ++i) {
            if (i != src && dist[i] <= distanceThreshold) {
                ans++;
            }
        }
   return ans;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<pii>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        
        int ans = INT_MAX;
        int curr_city=-1;
        for(int i=0;i<n;i++){
            int curr = dijkstra(n,adj,i,distanceThreshold);
          if(curr<ans){ curr_city = i;  ans = curr;}
            else if( curr==ans) curr_city = i;
            
        }
        return curr_city;
    }
};