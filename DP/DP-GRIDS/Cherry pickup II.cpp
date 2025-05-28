class Solution {
public:
    int func(int i,int j1,int j2,int n,int m,vector<vector<int>> &matrix,vector<vector<vector<int>>> &dp){
        
        //OutofBound test case
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
        //Destination test case
        if(i==n-1){
            if(j1==j2) return matrix[i][j1];
            else return matrix[i][j1]+matrix[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        //Exploration
        int maxi = INT_MIN;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                if(j1==j2) maxi = max(maxi,matrix[i][j1]+func(i+1,j1+d1,j2+d2,n,m,matrix,dp));
                else maxi = max(maxi,matrix[i][j2]+matrix[i][j1]+func(i+1,j1+d1,j2+d2,n,m,matrix,dp));
            }
        }
        return dp[i][j1][j2]=maxi;

    }
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,n,m,matrix,dp);
    }
};