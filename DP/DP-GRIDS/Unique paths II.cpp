class Solution {
public:
    int func(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
     if(i >= 0 && j >= 0 && matrix[i][j] == 1) return 0; 
        if(i == 0 && j == 0) return 1;                       
        if(i < 0 || j < 0) return 0;         
        if(dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1,j,matrix,dp);
        int left = func(i,j-1,matrix,dp);

        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,matrix,dp);
    }
};