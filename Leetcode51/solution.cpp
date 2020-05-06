class Solution 
{
public: 
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        NQueens(0, 0, n, board);
        
        return solution;
    }
    
    void NQueens(int row, int col, int n, vector<string>& board)
    {
        if(row == n) 
        {
            solution.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; j++)
        {
            if(check(row, j, n, board))
            {
                board[row][j] = 'Q';
                NQueens(row + 1, j, n, board);
                board[row][j] = '.';
            }
        }
        
        return;
    }
    
    bool check(int row, int col, int n, vector<string>& board)
    {
        
        for(int i = 0; i < row; i++)
        {
            if(board[i][col] == 'Q') return false;
        }
        
        
        for(int i = row-1, j = col-1; i >=0&&j>=0; i--, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        for(int i = row-1, j = col+1; i >=0&&j <n; i--, j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    private:
            vector<vector<string>> solution;
};
