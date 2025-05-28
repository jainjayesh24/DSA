class Solution{

    public:
      int solve(int currsum, vector<int> &arr,int index,int sum,vector<vector<int>> &dp){
          if(index == arr.size()) return abs(sum - 2*currsum);
          
          if(dp[index][currsum] != -1) return dp[index][currsum];
          //not_take
          int not_take = solve(currsum,arr,index+1,sum,dp);
  
          // take
          int take = solve(currsum+arr[index],arr,index+1,sum,dp);
          return dp[index][currsum] = min(take,not_take);
      }
      int minDifference(vector<int>&arr, int n)  { 
          int sum = 0;
          for(int i =0;i<arr.size();i++) sum += arr[i];
          vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
          return solve(0,arr,0,sum,dp);
      } 
  };
  