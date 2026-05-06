class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Phase 1:
        // Remove leaves with no coins
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 && coins[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            degree[node] = 0;

            for (int neigh : adj[node]) {

                if (degree[neigh] == 0)
                    continue;

                degree[neigh]--;

                if (degree[neigh] == 1 && coins[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Phase 2:
        // Remove 2 layers
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int rounds = 2;

        while (rounds-- && !q.empty()) {

            int sz = q.size();

            while (sz--) {

                int node = q.front();
                q.pop();

                degree[node] = 0;

                for (int neigh : adj[node]) {

                    if (degree[neigh] == 0)
                        continue;

                    degree[neigh]--;

                    if (degree[neigh] == 1)
                        q.push(neigh);
                }
            }
        }

        int remainingDegreeSum = 0;

        for (int d : degree)
            remainingDegreeSum += d;

        return remainingDegreeSum;
    }
};