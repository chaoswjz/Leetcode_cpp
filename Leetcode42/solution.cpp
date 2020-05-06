class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        if(height.size() == 0) return 0;
        vector<int> h(height.size(), 0);
        
        int lheight = 0;
        for(int i = 1; i < height.size(); i++)
        {
            lheight = max(lheight, height[i-1]);
            h[i] = lheight;
        }
        
        int rheight = 0;
        for(int i = height.size() - 2; i >= 0; i--)
        {
            rheight = max(rheight, height[i+1]);
            h[i] = min(h[i], rheight);
        }
        
        int res = 0;
        h[height.size()-1] = 0;
        for(int i = 0; i < height.size(); i++)
        {
            res += max(0, h[i] - height[i]);
        }
        
        return res;
    }
};
