class Solution {
public:
//  int f1(int row,int col,vector<vector<int>>matrix,vector<vector<int>>&dp){
//      if(row<0)return 0;
//      int left=1e8,right=1e8,down=1e8;
//     int val=matrix[row][col];
//     if(dp[row][col]!=-1)return dp[row][col];
//     down=val+f(row-1,col,matrix,dp);
//     if(col>0){
//         left=val+f(row-1,col-1,matrix,dp);
//     }
//     if(col<matrix.size()-1){
//         right=val+f(row-1,col+1,matrix,dp);
//     }
//     return  dp[row][col]=min({down,left,right});
//  }
 void  f(vector<vector<int>>matrix,vector<vector<int>>&dp){
       for(int row=1;row<=matrix.size();row++){  
            for(int col=0;col<matrix.size();col++){
                  int left=1e8,right=1e8,down=1e8;
                  int val=matrix[row-1][col];
                  down=val+dp[row-1][col];
              if(col>0){
                left=val+dp[row-1][col-1];
                  }
              if(col<matrix.size()-1){
                  right=val+dp[row-1][col+1];
                }
               dp[row][col]=min({down,left,right});
            }
       }
 }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e8;
        int n=matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n,0));
        f(matrix,dp);
        for(int i=0;i<matrix.size();i++){
            ans=min(ans,dp[n][i]);
        }
        return ans;
    }
};