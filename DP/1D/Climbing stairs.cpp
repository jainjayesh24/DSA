//Recursive 
class Solution {
    public:
        int climbStairs(int n) {
            // vector<int> dp(n+1,-1);
            if (n == 1 || n ==0) return 1;
    
            int one = climbStairs(n-1);
            int two = climbStairs(n-2);
            return one + two; 
        }
    };


//Memoization

class Solution {
    public:
        int fun(int n,vector<int> &dp){
            if (n == 1 || n ==0) return 1;
            if(dp[n]!=-1) return dp[n];
    
            return dp[n] = fun(n-1,dp)+fun(n-2,dp);
        }
        int climbStairs(int n) {
            vector<int> dp(n+1,-1);
            return fun(n,dp);
        }
    };


