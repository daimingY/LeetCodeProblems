class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int x = 0;
        int y = n-1;
        // rotate image ring by ring, from outer to inner
        while(x<y){
            for(int i=0;i<(x-y);++i){
                swap(matrix[x][x+i], matrix[x+i][y]);
                swap(matrix[x][x+i], matrix[y][y-i]);
                swap(matrix[x][x+i], matrix[y-i][x]);
            }
            ++x;
            --y;
        }
    }
};
