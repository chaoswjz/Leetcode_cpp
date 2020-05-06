class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solver(board, 0, 0);
        return;
    }
    
    bool solver(vector<vector<char>>& board, int row, int col)
    {
        if(row == 9) return true;
        if(col == 9) return solver(board, row+1, 0);
        if(board[row][col] != '.') return solver(board, row, col+1);
        
        for(int i = 1; i <= 9; i++)
        {
            if(check(board, row, col, i))
            {
                board[row][col] = i + '0';
                if(solver(board, row, col+1)) return true;
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    bool check(vector<vector<char>>& board, int row, int col, int n)
    {
        char num = n + '0';
        //check col
        for(int i = 0; i < 9; i++)
            if(board[i][col] == num) return false;
        
        //check row
        for(int i = 0; i < 9; i++)
            if(board[row][i] == num) return false;
        
        //check grid
        int grow = 3*(row / 3);
        int gcol = 3*(col / 3);
        
        for(int i = grow; i < grow + 3; i++)
        {
            for(int j = gcol; j < gcol + 3; j++)
            {
                if(board[i][j] == num) return false;
            }
        }
        
        return true;
    }
};
