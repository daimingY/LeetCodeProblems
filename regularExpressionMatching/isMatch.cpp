class Solution {
public:
    // note, only p may contain '*' or '.'
    bool isMatch(string s, string p) {
        // using DP, initilize 2D array with base cases
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        // i, j represent char positions in string s, p
        // dp[i][j] is true when s[0:i) matches p[0:j)
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                // three possible scenarios:
                // 1) last char in p was *, then dp[i][j] = dp[i][j-2] for including 0 times of preceding char
                // 2) last char in p was *, then dp[i][j] = dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.') for repeating at least 1 time
                // 3) last char in p wasn't *, then check curr pair of (i-1, j-1) and maintain from dp[i-1][j-1]
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        // answer stored in the last cell
        return dp[m][n];
    }
};
