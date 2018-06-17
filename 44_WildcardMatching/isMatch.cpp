class Solution {
public:
    bool isMatch(string s, string p) {
        // initialize a 2D bool array with false
        // dp[i][j] means if s[0, i-1] and p[0, j-1] match
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        // base case
        dp[0][0] = true;

        // special case to deal with p starts with multiple '*'s
        for(int j=1; j<=p.size(); j++)
        {
            if(p[j-1]=='*')
                dp[0][j] = true;
            else
                break;
        }

        // filling the array
        for (int i=1; i<=s.size(); i++)
        {
            for (int j=1; j<=p.size(); j++)
            {
                // if match, same as without
                if (s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                // if doesn't match, try to deal with star
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }

        return dp.back().back();
    }
};

