class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int n = matrix.size(), m = matrix[0].size();
        bool row0 = false; // whether first row contains 0
        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0){
                row0 = true;
                break;
            }
        }
        // scan all elements. put 0 in first row for columns
        for(int i = 1; i < n; i++){
            bool row = false;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    row = true;
                }
            }
            if(row){
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        // fill columns
        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0)
                for(int i = 1; i < n; i++){
                    matrix[i][j] = 0;
                }
        }
        // fill first row if necessary
        if(row0){
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
    }
};
