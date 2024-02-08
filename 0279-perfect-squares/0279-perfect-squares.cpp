class Solution {
public:
int solve(vector<int>nums,int index,int target,vector<vector<int>>&dp){
    if(index<0){
        if(target==0)return 0;
        //if(nums[index]==target)return 1;
        return 1e9;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    int pick=1e9;
    if(nums[index]<=target){
        pick=1+solve(nums,index,target-nums[index],dp);
    }
    int notpick=solve(nums,index-1,target,dp);
    return dp[index][target]=min(pick,notpick);
}
    int numSquares(int n) {
          vector<int>v;
          for(int i=1;i*i<=n;i++){
              v.push_back(i*i);
          }
          vector<vector<int>>dp(v.size()+1,vector<int>(n+1,-1));
          for(int i=0;i<=n;i++){
          if(i%v[0]==0)dp[0][i]=i/v[0];
          else dp[0][i]=1e9;
          } 
          for(int i=1;i<v.size();i++){
              for(int t=0;t<=n;t++){
                  int pick=1e9;
                if(v[i]<=t){
                    pick=1+dp[i][t-v[i]];
                  }
                int notpick=dp[i-1][t];
               dp[i][t]=min(pick,notpick);
              }
          }
          return dp[v.size()-1][n];

    }
};