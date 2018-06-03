class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> val;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        recur(val, candidates.begin(), candidates, res, target);
        return res;
    }
private:
    void recur(vector<int> &val, vector<int>::iterator p, vector<int> &cad, vector<vector<int>> &res, int target) {
        if (target == 0) {res.push_back(val); return;}
        while (p != cad.end()) {
            if (*p > target) break;
            val.push_back(*p);
            recur(val, p+1, cad, res, target-*p);
            val.pop_back();
            p = upper_bound(cad.begin(), cad.end(), *p);
        }
    }
};
