class Solution {
public:
    string getPermutation(int n, int k) {
        // given n between 1 and 9, pre-calculation of factors is feasible
        string retVal;
        string nums = "123456789";
        int fac[10] = {0, 1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        --k;
        for(int i = n; i > 0; --i){
            int j = k / fac[i];
            k %= fac[i];
            retVal.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return retVal;
    }
};
