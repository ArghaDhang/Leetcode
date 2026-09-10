class Solution {
public:

    void dfs(int i, int j,
             vector<vector<bool>>& vis,
             vector<vector<char>>& grid,
             int rows, int cols) {

        // Boundary condition
        if (i < 0 || j < 0 ||
            i >= rows || j >= cols ||
            vis[i][j] ||
            grid[i][j] != '1') {
            return;
        }

        // Mark current cell as visited
        vis[i][j] = true;

        // Top
        dfs(i - 1, j, vis, grid, rows, cols);

        // Right
        dfs(i, j + 1, vis, grid, rows, cols);

        // Bottom
        dfs(i + 1, j, vis, grid, rows, cols);

        // Left
        dfs(i, j - 1, vis, grid, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(
            rows, vector<bool>(cols, false)
        );

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {

                    dfs(i, j, vis, grid, rows, cols);

                    islands++;
                }
            }
        }

        return islands;
    }
};