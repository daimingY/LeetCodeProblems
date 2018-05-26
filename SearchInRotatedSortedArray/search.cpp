class Solution {
public:
    int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int s = 0, e = nums.size()-1, pos = -1;
		while (s <= e) {
			if (s == e && nums[s] != target) break;
			int mid = (s + e) / 2;
			if (nums[mid] == target) return mid;
			else if (mid-1 >= 0 && s<=mid-1 && nums[s]<=nums[mid - 1] && target >=nums[s] && target <= nums[mid - 1]) e = mid - 1;
			else if (mid+1 < nums.size() && e>=mid+1 && nums[mid + 1]<=nums[e] && target>=nums[mid + 1] && target <= nums[e]) s = mid + 1;
			else if (mid-1 >= 0 && s<=mid-1 && nums[s] > nums[mid - 1]) e = mid - 1;
			else if (mid+1 < nums.size() && e>=mid+1  && nums[mid + 1] > nums[e]) s = mid + 1;
			else return -1;
		}
		return pos;
    }
};
