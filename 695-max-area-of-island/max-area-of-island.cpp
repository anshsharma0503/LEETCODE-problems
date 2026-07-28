class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(int r, int c, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;  

        int area = 1;

        for (int k = 0; k < 4; k++) {
            area += dfs(r + dr[k], c + dc[k], grid);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};