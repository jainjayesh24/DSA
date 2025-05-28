//Recursive

class Solution {
    public:
        int func(int i, int j){
            // Base case
            if(i==0 && j==0) return 1;
            if(i<0 || j<0) return 0;
    
            //Exploration
            int up = func(i-1,j);
            int left = func(i,j-1);
    
            return up+left;
    
    
        }
        int uniquePaths(int m, int n) {
    
            return func(m-1,n-1);
        }
    };


//DP
//Memoization
class Solution {
    public:
        int func(int i, int j,vector<vector<int>> &dp){
            // Base case
            if(i==0 && j==0) return 1;
            if(i<0 || j<0) return 0;
    
            //if path aldready explored 
    
            if(dp[i][j]!=-1) return dp[i][j];
            //Exploration
            int up = func(i-1,j,dp);
            int left = func(i,j-1,dp);
    
            return dp[i][j]=up+left;
    
    
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return func(m-1,n-1,dp);
        }
    };

//Time Complexity:The time complexity is O(m*n) because each cell in the dp table is visited at most once.
// Space Complexity:The space complexity is O(m*n) due to the dp table and the recursion stack space, which is proportional to the product of m and n in the worst case.

//Tabluation
class Solution {
    public:
        int func(int m,int n,vector<vector<int>> &dp){
            for(int i=0;i<m;i++){
                for(int j =0;j<n;j++){
    
                    if(i==0 && j==0){
                        dp[i][j]=1;
                        continue;
    
                    }
                    int up = 0;
                    int left = 0;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
            return dp[m-1][n-1];
    
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return func(m,n,dp);
        }
    };