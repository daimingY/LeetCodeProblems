class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       SDK_MEM_T sdk_mem = {false};
       vector<pair<int, int>> ept_grd;
       vector<int> ept_blk;
       int col_2_blk[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
       int row_2_blk[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
       int blk_row_idx, blk_idx, num;
       char chr;

       for(int idx1 = 8; idx1 >= 0; --idx1)
       {
          blk_row_idx = row_2_blk[idx1];

          for(int idx2 = 8; idx2 >= 0; --idx2)
          {
             chr = board[idx1][idx2];
             blk_idx = blk_row_idx + col_2_blk[idx2];

             if(chr == '.')
             {
                ept_grd.push_back({idx1, idx2});
                ept_blk.push_back(blk_idx);
             }
             else
             {
                num = chr - '1';
                sdk_mem.blk[blk_idx][num] = sdk_mem.row[idx1][num] = sdk_mem.col[idx2][num] = true;
             }
          }
       }

       sdk_solver(sdk_mem, ept_grd, ept_blk, board);

       return;
    }

private:
    typedef struct
    {
       bool blk[9][9];
       bool row[9][9];
       bool col[9][9];
    }SDK_MEM_T;

    bool sdk_solver(SDK_MEM_T &sdk_mem, vector<pair<int, int>> &ept_grd, vector<int> &ept_blk, vector<vector<char>> &board)
    {
       int row, col, blk;

       if(ept_grd.empty())
       {
          return true;
       }

       row = ept_grd.back().first;
       col = ept_grd.back().second;
       blk = ept_blk.back();

       for(int idx1 = 0; idx1 < 9; ++idx1)
       {
          if((!sdk_mem.blk[blk][idx1]) && (!sdk_mem.row[row][idx1]) && (!sdk_mem.col[col][idx1]))
          {
             sdk_mem.blk[blk][idx1] = sdk_mem.row[row][idx1] = sdk_mem.col[col][idx1] = true;
             ept_grd.pop_back();
             ept_blk.pop_back();
             board[row][col] = idx1 + '1';

             if(sdk_solver(sdk_mem, ept_grd, ept_blk, board))
             {
                return true;
             }

             sdk_mem.blk[blk][idx1] = sdk_mem.row[row][idx1] = sdk_mem.col[col][idx1] = false;
             ept_grd.push_back({row, col});
             ept_blk.push_back(blk);
             board[row][col] = '.';
          }
       }

       return false;
    }
};
