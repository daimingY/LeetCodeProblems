/*
 * A greedy solution using BFS inherently
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(), step = 0, currStart = 0, currEnd = 0;
        // loop until the end is reached
        while(currEnd < (size - 1)){
            step++;
            int endMax = currEnd + 1;
            // loop through currently reachable positions
            // using BFS inherently, to get the farthest reachable position
            for(int i = currStart; i <= currEnd; i++){
            	// if the final position is in range, return
                if((i + nums[i]) >= (size - 1)) return step;
                endMax = max(endMax, i + nums[i]);
            }
            // redefine range for the next loop
            currStart = currEnd + 1;
            currEnd = endMax;
        }
        return step;
    }
};
