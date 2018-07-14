class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	// O(log(mn)) possible by using two binary searches,
    	// but this method runs faster on LeetCode
        int  i = 0, j;
        if(matrix.size() > 0){
            j = matrix[0].size()-1;
        }
        while (j >= 0 && i < matrix.size()) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};
