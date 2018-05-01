class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retVal;
        // sort the array O(n^logn)
        std::sort(nums.begin(), nums.end());
        // loop through each number
        int size = nums.size();
        if(size < 3){
            return retVal;
        }
        for(int i = 0; nums[i] <= 0; i++){
            // set target as negative first number
            int target = -nums[i];
            // then perform two sum
            int front = i + 1;
            int back = size - 1;
            while(front < back){
                int sum = nums[front] + nums[back];
                // check sum vs. target
                if(sum < target){ front++; } // less negative
                else if(sum > target){ back--; } // less positive
                else{ // found an answer
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    retVal.push_back(triplet);
                    
                    // forward front to a new number
                    while(nums[front] == triplet[1]) front++;
                    // backward back to a new number
                    while(nums[back] == triplet[2]) back--;
                }
            }
            // forward first number to a new number
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