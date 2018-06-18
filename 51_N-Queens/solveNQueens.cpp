class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > retVal;
        int pos[n+1] = {0}, k = 1, i, t = 0;

        while(k > 0){
            pos[k]++;
            while((pos[k] <= n) && !(place(k, pos))) pos[k]++;
            if(pos[k] <= n){
                if(k == n){ // a solution exists
                    vector<string> board(n, string(n, '.'));
                    for(i = 1; i <= n; i++) board[i - 1][pos[i] - 1] = 'Q'; // enter Q into board
                    retVal.push_back(board);
                }else{
                    k++; pos[k] = 0;
                }
            }else{
                k--;
            }
        }
        return retVal;
    }

    int place(int k, int pos[]){
        for(int i = 1; i < k; i++){
            if((pos[i] == pos[k]) || (abs(pos[i] - pos[k]) == abs(i-k)))
                return 0;
        }
        return 1;
    }
};

