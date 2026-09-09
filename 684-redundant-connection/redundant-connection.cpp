class Solution {
public:
    bool bfs(int start, int target, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == target)
                return true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If u and v are already connected,
            // adding this edge creates a cycle
            if (bfs(u, v, adj, n)) {
                return {u, v};
            }

            // Otherwise add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};