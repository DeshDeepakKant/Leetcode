class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(i<j)
        {
            ans=max(ans,((j-i)*min(height[i],height[j])));
            // if(min(height[i+1],height[j])>min(height[i],height[j-1]))
            // {
            //     i++;
            // }
            // else
            // {
            //     j--;
            // }
             if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};