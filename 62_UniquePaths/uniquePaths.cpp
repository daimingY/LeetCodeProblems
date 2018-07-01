class Solution {
public:
    int uniquePaths(int m, int n) {
        // maintain 1D array
        if (m > n) return uniquePaths(n, m);
        vector<int> curr(m, 1);
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                curr[j] += curr[j-1];
            }
        }
        return curr[m - 1];
    }
};
