class Solution {
public:

    void dfs(int node , vector<vector<int>>& isConnected , vector<int>& seen){
        seen[node] = 1;

        for(int col = 0 ; col < isConnected.size() ; col++){
            if(!seen[col] && isConnected[node][col] == 1){
                dfs(col , isConnected , seen);  
          }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> seen(n , 0);
        int res = 0;
        for(int i = 0; i < n ; i++){
            if(!seen[i]){
                dfs(i ,  isConnected , seen);
                res++;
            }
        }

        return res;
    }
};