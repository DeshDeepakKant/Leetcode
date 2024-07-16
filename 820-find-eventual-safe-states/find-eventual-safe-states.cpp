class Solution {
public:
    bool dfs(int i,vector<int> &vis,vector<int> & rvis,vector<vector<int>>& graph )
    {
        vis[i]=1;
        rvis[i]=1;
        for(auto it: graph[i])
        {
            if((!vis[it])&&(dfs(it,vis,rvis,graph)))
            {
                return true;
            }
            else if(rvis[it])
            {
                return true;
            }
        }
        rvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> rvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool x = dfs(i, vis, rvis, graph);
            }
        }
       vector<int> ans;
       for(int i=0;i<n;i++)
       {
        if(!rvis[i])
        {
            ans.push_back(i);
        }
       } 
       return ans;
    }
};