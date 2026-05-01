class Solution {
public:

    vector<int> vis;

    bool dfs(int node , vector<vector<int>>& adj, vector<int>& ans){
        if(vis[node] == 2) return false;
        if(vis[node] == 1) return true;
        vis[node] = 1;

        for(auto x : adj[node]){
            if(dfs(x , adj , ans)) return true;
        }
        vis[node] = 2;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n =  numCourses;
        vector<vector<int>> adj(n);

        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);

        }

        vector<int> ans;
        vis.resize(n  , 0);

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0) {
                if(dfs(i , adj , ans)) return {};
            }
        }


        reverse(ans.begin() , ans.end());
        return ans;

    }
};