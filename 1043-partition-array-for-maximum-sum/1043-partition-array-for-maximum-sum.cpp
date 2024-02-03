class Solution {
public:
int f(int ind,vector<int>& nums,int k,vector<int>&dp){
    if(ind==nums.size())return 0;
    int len=0,maxi=INT_MIN;
    int maxans=INT_MIN;
    if(dp[ind]!=-1)return dp[ind];
    for(int j=ind;j<ind+k&&j<nums.size();j++){
        len++;
        maxi=max(maxi,nums[j]);
        int sum=len*maxi+f(j+1,nums,k,dp);
        maxans=max(maxans,sum);

    }
    return dp[ind]=maxans;

    
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        int n=arr.size();
        for(int i=arr.size()-1;i>=0;i--){
            int len=0,maxi=INT_MIN,maxans=INT_MIN;
            for(int j=i;j<i+k&&j<n;j++){
                   len++;
                   maxi=max(maxi,arr[j]);
                   int sum=len*maxi+dp[j+1];
                   maxans=max(maxans,sum);
            }
            dp[i]=maxans;
        }
        return dp[0]+1;

        return f(0,arr,k,dp);
    }
};