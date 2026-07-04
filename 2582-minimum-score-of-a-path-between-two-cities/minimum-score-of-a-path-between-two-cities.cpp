class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis)
    {
        // current node visit kar diya
        vis[node] = 1;

        // current node ki saari edges dekho
        for(auto &it : adj[node])
        {
            int next = it.first;
            int dist = it.second;

            // connected component ki minimum edge maintain karo
            ans = min(ans, dist);

            // agar next node visit nahi hui to DFS karo
            if(!vis[next])
                dfs(next, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        // adjacency list
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it : roads)
        {
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<int> vis(n+1,0);

        // city 1 ke connected component traverse karo
        dfs(1, adj, vis);

        return ans;
    }
};