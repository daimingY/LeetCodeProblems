class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0, lastPos = nums.size() - 1;
        for(int i = 0; i <= maxPos && i < lastPos; i++){
            maxPos = max(i + nums[i], maxPos);
        }
        return maxPos >= lastPos;
    }
};
