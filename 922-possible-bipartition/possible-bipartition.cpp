class Solution {
public:
    bool bfs(int i, vector<int> adj[], vector<int>& vis) {
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto it : adj[x]) {
                if (vis[it] == vis[x]) {
                    return false;
                }
                if (vis[it] == -1) {
                    vis[it] = 1 - vis[x];
                    q.push(it);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& v) {
        vector<int> adj[n + 1];
        for (auto it : v) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bool ans = true;

        vector<int> vis(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1) {
                if (!bfs(i, adj, vis)) {
                    return false;
                }
            }
        }
        return ans;
    }
};