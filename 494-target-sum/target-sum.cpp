class Solution {
public:
    int ans=0;
    void f(int i,vector<int>& v,int t,int s)
    {
       if(i<0)
       {
         if(s==t)
         {
            ans++;
         }
         return;
       }
       f(i-1,v,t,s+v[i]);
       f(i-1,v,t,s-v[i]);
       return;
       
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        f(nums.size()-1,nums,target,0);
        return ans;
    }
};