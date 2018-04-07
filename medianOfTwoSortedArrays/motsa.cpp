class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	// ensure array 1 is less than array 2
        unsigned int length1 = nums1.size(), length2 = nums2.size();
        if(length1 > length2){
        	return findMedianSortedArrays(nums2, nums1);
        }

        double retVal = 0;
        unsigned int l1 = 0, r1 = length1, halfLen = (length1 + length2 + 1) / 2;
        unsigned int i1, i2; // index for two arrays
        // use divide-and-conquer to divide each array to two sets
        // squeeze the answer to four numbers
        while(l1 <= r1){
        	i1 = (l1 + r1) / 2;
        	i2 = halfLen - i1;
        	if(i1 < r1 && nums2[i2 - 1] > nums1[i1]){
        		l1 = i1 + 1; // i1 is too small
        	}else if(i1 > l1 && nums1[i1 - 1] > nums2[i2]){
        		r1 = i1 - 1; // i1 is too large
        	}else{
        		int maxLeft = 0;
        		if(i1 == 0) {
        			maxLeft = nums2[i2 - 1];
        		}else if(i2 == 0){ 
        			maxLeft = nums1[i1 - 1];
        		}else{
        			maxLeft = max(nums1[i1 - 1], nums2[i2 - 1]);
        		}
        		if((length1 + length2) & 1 == 1){ // if odd
        			return maxLeft;
        		}

        		int minRight = 0;
        		if(i1 == length1){
        			minRight = nums2[i2];
        		}else if(i2 == length2){
        			minRight = nums1[i1];
        		}else{
        			minRight = min(nums1[i1], nums2[i2]);
        		}

        		return (maxLeft + minRight) / 2.0;
        	}
        }
    }
};