class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f(int i , int j , int k , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if( j <0 || k < 0|| j == n || k ==n)
            return -1e9;


        if(i == m - 1){
            if(j == k)
                return grid[i][j];
            return grid[i][j] + grid[i][k];
        }

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        int curr;
        if(j==k) curr = grid[i][j];
        else curr = grid[i][j] + grid[i][k];

        int maxi=-1e9;
        for (int dj = -1; dj <= 1; dj++) {
            for (int dk = -1; dk <= 1; dk++) {
                maxi = max(maxi , f(i + 1, j + dj, k + dk, grid));
            }
        }

        return dp[i][j][k] = curr + maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m , vector<vector<int>> (n , vector<int> (n , -1)));

        return f(0 , 0 , n-1 , grid);
    }
};