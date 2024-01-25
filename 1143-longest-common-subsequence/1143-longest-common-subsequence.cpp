class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.size(),l2=text2.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
            for(int i=l1-1;i>=0;i--){
                for(int j=l2-1;j>=0;j--){
                    int pick1=0,pick2=0,pick3=0;
                    if(text1[i]==text2[j]){
                        pick1=1+dp[i+1][j+1];                        
                    }
                    pick2=dp[i+1][j];
                    pick3=dp[i][j+1];
                    dp[i][j]=max({pick1,pick2,pick3});
                }
            }
        return dp[0][0];
    }
};