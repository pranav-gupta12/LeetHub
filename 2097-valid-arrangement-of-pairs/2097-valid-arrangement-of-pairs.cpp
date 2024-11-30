
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, list<int>> graph;
        unordered_map<int, int> inDegree, outDegree;

        // Step 1: Build the graph and count degrees
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Step 2: Find the starting point for the Eulerian path
        int start = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }

        // Step 3: Perform Hierholzer's algorithm to find the path
        stack<int> dfsStack;
        vector<int> path;
        dfsStack.push(start);

        while (!dfsStack.empty()) {
            int node = dfsStack.top();
            if (graph[node].empty()) {
                path.push_back(node);
                dfsStack.pop();
            } else {
                int nextNode = graph[node].back();
                graph[node].pop_back();
                dfsStack.push(nextNode);
            }
        }

        // Step 4: Construct the result from the path
        vector<vector<int>> result;
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};
