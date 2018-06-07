class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // swap numbers into their right places
        // in the end, the first position with wrong number is missed
        for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        // find the first missing number
        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
