class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        sort(nums.begin(),nums.end());
        vector<int>hash(n,0);
        int ans=1;
        int lastindex=0;
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&(dp[j]+1)>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>ans){
                ans=dp[i];
                lastindex=i;
            }
        }
        vector<int>fans;
        fans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
             lastindex=hash[lastindex];
            fans.push_back(nums[lastindex]);

        }
        sort(fans.begin(),fans.end());
       return fans;
    }
};