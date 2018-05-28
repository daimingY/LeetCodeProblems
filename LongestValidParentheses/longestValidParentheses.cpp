class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
        /*int n = s.size(), maxLen = 0;
        vector<int> dp(n+1,0);
        for(int i=0; i<n; i++) {
            int j = i-1-dp[i];
            if(s[i]=='(' || j<0 || s[j]==')')
                dp[i+1] = 0;
            else {
                dp[i+1] = dp[i]+2+dp[j];
                maxLen = max(maxLen, dp[i+1]);
            }
        }
        return maxLen;*/
    }
};
