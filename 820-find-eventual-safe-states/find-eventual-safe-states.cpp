class Solution {
public:

    vector<int> state; 

    bool dfs(int node, vector<vector<int>>& graph) {
        if (state[node] == 1) return false; 
        if (state[node] == 2) return true;  

        state[node] = 1;

        for (auto v : graph[node]) {
            if (!dfs(v, graph)) {
                return false; 
            }
        }

        state[node] = 2; 
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.resize(n, 0);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph)) {
                result.push_back(i);
            }
        }

        return result;
    }
};