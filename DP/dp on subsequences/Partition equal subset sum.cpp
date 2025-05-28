class Solution {
    public:
     bool solve(int x, vector<int> &arr, int i,vector<vector<int>> &dp) {
         // base case
         if (x == 0) return true;
         if (i == arr.size()) return false;
         // not_take
         if(dp[i][x] != -1) return dp[i][x];
         bool not_take = solve(x, arr, i + 1,dp);
         bool take = false;
 
         // take
         if (x >= arr[i]) {
             take = solve(x - arr[i], arr, i + 1,dp);
         }
 
         return dp[i][x] = take || not_take;
     }
     bool equalPartition(int n, vector<int> arr) {
         int sum = 0;
         for (int i = 0; i < arr.size(); i++) {
             sum += arr[i];
         }
         if (sum % 2 != 0) return 0;
         int target = sum / 2;
         vector<vector<int>> dp(n,vector<int>(target+1,-1));
         return solve(target, arr, 0,dp);
     }
 };
 