class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> retVal;
        string str;
        putString(n, 0, 0, str, 0, retVal);
        return retVal;
    }

    void putString(int n, int left, int right, string& str, int length, vector<string>& retVal){
        // base case when a valid string appears
        if(length == n * 2){
            retVal.push_back(str);
            return;
        }
        // first case, try '('
        if(left < n){
            str.push_back('(');
            putString(n, left+1, right, str, length+1, retVal);
            str.pop_back();
        }
        // second case, try ')'
        if(right < left){
            str.push_back(')');
            putString(n, left, right+1, str, length+1, retVal);
            str.pop_back();
        }
    }
};
