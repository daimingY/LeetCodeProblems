class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        help(res, nums, 0);
        return res;
    }
    void help(vector<vector<int> > & res, vector<int> nums, int pos){
        if(pos == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        else{
            for(int i = pos; i < nums.size(); ++i){
                swap(nums[i], nums[pos]);
                help(res, nums, pos + 1);
            }
        }
    }
};
