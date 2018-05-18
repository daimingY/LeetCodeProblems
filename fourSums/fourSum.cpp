class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::unordered_set <std::string> myset;
        vector<vector<int>> res;
        int n = nums.size();
        if (n<4)
                        return res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-3;i++){
            int target2=-nums[i];
            for(int j=i+1;j<nums.size()-2;j++){
                int target3=-nums[j];
                int ptr1=j+1;
                int ptr2= nums.size()-1;
                while(ptr1<ptr2){
                    int sum=nums[ptr1]+nums[ptr2]-target2-target3;
                    if (sum==target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[ptr1]);
                        temp.push_back(nums[ptr2]);
                        string s=to_string(nums[i])+to_string(nums[j])+to_string(nums[ptr1])+to_string(nums[ptr2]);

                        if (myset.find (s)==myset.end()){
                            myset.emplace(s);
                            res.push_back(temp);
                        }


                        while(nums[ptr1]==temp[0])
                            ptr1++;
                        while(nums[ptr2]==temp[1])
                            ptr2--;
                        ptr1++;
                    }else{
                        if (sum>target)
                            ptr2--;
                        else
                            ptr1++;

                    }
                // Processing duplicates of Number 1
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;
                }
            }
        }
        return(res);
    }
};
