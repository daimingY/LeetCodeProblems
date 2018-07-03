class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // initialize 2D array
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        // base case
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        // iterative calculation
        for (int j = 1; j < n; j++) {
            // base case for each col
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                // 2 cases
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            // if entire row is blocked
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
};
