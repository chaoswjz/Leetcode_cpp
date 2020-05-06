class Solution 
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        //prefix sum for all rows
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[i].size(); j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int res = 0;
        for(int i = 0; i < matrix[0].size(); i++)
        {
            for(int j = i; j < matrix[0].size(); j++)
            {
                unordered_map<int, int> m;
                m[0] = 1;
                int sum = 0;
                for(int k = 0; k < matrix.size(); k++)
                {
                    sum += matrix[k][j] - (i == 0 ? 0 : matrix[k][i-1]);
                    if(m.find(sum - target) != m.end())
                        res += m.find(sum - target)->second;
                    m[sum]++;
                }
            }
        }
        return res;
    }
};
