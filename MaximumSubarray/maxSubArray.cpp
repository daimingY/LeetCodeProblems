class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int glob_max = INT_MIN;
        int sub_prev = 0;
        for(int i = 0; i < int(nums.size()); ++i){
            sub_prev = max(nums[i], sub_prev+nums[i]);
            glob_max = max(sub_prev, glob_max);
        }
        return glob_max;
    }
};
