class Solution {
public:
    int check(vector<vector<int>>&dp,string s,int i,int j){
        if(j-i<=1){
            if(s[i]==s[j]){
                return j-i+1;
            }
            return -1e9;
        }
        if(dp[i][j]>0){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==s[j]){
            ans=2+check(dp,s,i+1,j-1);
        }
        else{
            ans=-1e9;
        }
        return dp[i][j]=ans;
    }
    int countSubstrings(string s) {
        int n=size(s);
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check(dp,s,i,j)>0){
                    ans++;
                }
            }
        }
        return ans;
    }
};