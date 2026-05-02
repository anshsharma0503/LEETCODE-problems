class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }

        queue<int> q;
        for(int i = 0 ;i < n ; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int rem = n;
        while(rem > 2){
            int len = q.size();
            rem -= len;

            while(len--){
                int node = q.front();
                q.pop();

                for(auto x : adj[node]){
                    indegree[x]--;
                    if(indegree[x] == 1) q.push(x);
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};