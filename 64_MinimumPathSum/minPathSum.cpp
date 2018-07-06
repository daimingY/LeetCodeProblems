class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // initialize vector
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        // base case row
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];
        // iterative calculations
        for (int j = 1; j < n; j++) {
            // base case first col
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
