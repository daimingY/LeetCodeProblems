class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // base case
        if(matrix.empty()) return {};
        // get parameters
        int m = matrix.size(), n = matrix[0].size();
        // pre-allocating
        vector<int> spiral(m * n);
        // initialize indicies
        int t = 0, b = m - 1, l = 0, r = n - 1, k = 0;
        // going spirally
        while(true){
            // top row
            for(int col = l; col <= r; col++)
                spiral[k++] = matrix[t][col];
            if(++t > b)
                break;
            // right col
            for(int row = t; row <= b; row++)
                spiral[k++] = matrix[row][r];
            if(--r < l)
                break;
            // bottom row
            for(int col = r; col >= l; col--)
                spiral[k++] = matrix[b][col];
            if(--b < t)
                break;
            for(int row = b; row >= t; row--)
                spiral[k++] = matrix[row][l];
            if(++l > r)
                break;
        }
        return spiral;
    }
};
