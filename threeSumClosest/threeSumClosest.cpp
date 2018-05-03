class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int retVal = 0;
        int diff = ~(1<<31);
        // sort the array O(n^logn)
        std::sort(nums.begin(), nums.end());
        // loop through each number
        int size = nums.size();
        if(size < 3){
            return retVal;
        }
        for(int i = 0; i < size; i++){
            // set target as negative first number
            int currTarget = -nums[i] + target;
            // then perform two sum
            int front = i + 1;
            int back = size - 1;
            while(front < back){
                int sum = nums[front] + nums[back];
                // check sum vs. target
                if(sum == currTarget) { // exact solution
                    return target;
                }else{
                    if(abs(sum - currTarget) < diff){
                        diff = std::abs(sum - currTarget);
                        retVal = sum + nums[i];
                    }
                    if(sum < currTarget) {
                        front++;
                    }else{
                        back--;
                    }
                }
            while(1){
                if(i + 1 < size){
                    if(nums[i + 1] == nums[i]){ i++; }
                    else{ break; }
                }else{
                    return retVal;
                }
            }
        }
        return retVal;
    }
};
