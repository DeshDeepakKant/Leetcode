class Solution {
public:
    bool ans = false;
    void dfs(int s, int d, vector<int> adj[], vector<int> &vis) {
        vis[s] = 1;
        if (s == d) {
            ans = true;
        }
        for (auto it : adj[s]) {
            if (!vis[it]) {
                vis[it] = 1;
                dfs(it, d, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        // int m = e.size();
        // int nn = e[0].size();
        vector<int> adj[n];
        for (auto it : e) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        dfs(s, d, adj, vis);
        return ans;
    }
};