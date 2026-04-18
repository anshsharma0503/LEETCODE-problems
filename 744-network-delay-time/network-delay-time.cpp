class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times){
            int u = it[0];
            int v= it[1];
            int w = it[2];

            adj[u].push_back({v , w});
        }

        vector<int> dist(n+1 ,1e9);
        dist[k] = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0 , k});

        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]){
                auto neighbor = it.first;
                auto weight = it.second;

                if(d + weight < dist[neighbor]){
                    dist[neighbor] = d + weight;
                    pq.push({dist[neighbor] , neighbor});
                }
            }
        }

        int res = 0;
        for(int i = 1 ; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            res = max(res , dist[i]);
        }

        return res;
    }
};