class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	// initialize three vectos
        vector<short> col(9, 0);
        vector<short> block(9, 0);
        vector<short> row(9, 0);
        // loop through each square
        for (int i = 0; i < 9; i++)
         for (int j = 0; j < 9; j++) {
         	// perform check on non-dot squares
            if (board[i][j] != '.') {
            	// get number
                int idx = 1 << (board[i][j] - '0');
                // perform check with bit operations
                if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                   return false;
                row[i] |= idx;
                col[j] |= idx;
                block[i/3 * 3 + j/3] |= idx;
            }
        }
        return true;
    }
};
