class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()) return 0;
        if(matrix[0].size() == 0) return 0;
        vector<vector<int>> path(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int res = INT_MIN;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                res = max(res, dfs(matrix, i, j, INT_MIN, path));
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int pre, vector<vector<int>>& path)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size() || matrix[i][j] <= pre)
            return 0;
        
        if(path[i][j]) return path[i][j];
        
        int up = dfs(matrix, i-1, j, matrix[i][j], path) + 1;
        int down = dfs(matrix, i+1, j, matrix[i][j], path) + 1;
        int left = dfs(matrix, i, j-1, matrix[i][j], path) + 1;
        int right = dfs(matrix, i, j+1, matrix[i][j], path) + 1;
        path[i][j] = max({up, left, down, right});
        
        return path[i][j];
    }
};
