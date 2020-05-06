class Solution 
{
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        if(s.size() == 0) 
        {
            vector<string> a;
            a.push_back(s);
            return a;
        }
        unordered_set<string> res_set;
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') left++;
            if(s[i] == ')') 
            {
                if(left != 0)
                    left--;
                else
                    right++;
            }
        }
        dfs(s, "", 0, 0, left, right, res_set);
        
        return vector<string> (res_set.begin(), res_set.end());
    }
    
    void dfs(string s, string res, int index, int pair, int left, int right, unordered_set<string>& res_set)
    {
        if(index == s.size())
        {
            if(pair == 0 && left == 0 && right == 0)
            {
                res_set.insert(res);
            }
            return;
        }
        
        
        if(s[index] != '(' && s[index] != ')')
        {
            dfs(s, res+s[index], index+1, pair, left, right, res_set);
        }
        else
        {
            if(s[index] == '(')
            {
                if(left > 0)
                {
                    dfs(s, res, index+1, pair, left-1, right, res_set);
                }
                dfs(s, res+s[index], index+1, pair+1, left, right, res_set);
            }

            if(s[index] == ')')
            {
                if(right > 0)
                {
                    dfs(s, res, index+1, pair, left, right-1, res_set);
                }
                if(pair > 0)
                {
                    dfs(s, res+s[index], index+1, pair-1, left, right, res_set);
                }
            }
        }
    }
};
