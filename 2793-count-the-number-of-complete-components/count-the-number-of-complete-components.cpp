class Solution {
public:

    void dfs(int node , int n , vector<vector<int>>& edges , vector<vector<int>>& adj , vector<int>& comp ,  vector<int>& vis){
        vis[node] = 1;
        comp.push_back(node);

        for(int nei : adj[node]){
            if(!vis[nei]){
                dfs(nei , n , edges , adj , comp , vis);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n , 0);
        int res = 0;

        for(int i = 0; i < n ; i++){
            if(vis[i] == 1) continue;

            vector<int> comp;
            dfs(i , n , edges ,adj , comp , vis);

            int nodes = comp.size();
            int edges = 0;

            for(int u : comp){
                edges += adj[u].size();
            }

            edges /= 2;

            if(edges == nodes * (nodes - 1) / 2){
                res++;
            }
        }

        return res;
    }
};