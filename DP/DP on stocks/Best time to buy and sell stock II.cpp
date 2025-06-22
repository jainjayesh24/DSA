class Solution{
public:
    int func(int ind,vector<int> &arr,vector<vector<int>> &dp,int buy,int n){
        //Base case
        if(ind == n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;

        if(buy){
            profit = max(-arr[ind]+func(ind+1,arr,dp,0,n) , func(ind+1,arr,dp,1,n));
        }

        else{
            profit = max(arr[ind]+func(ind+1,arr,dp,1,n),func(ind+1,arr,dp,0,n));
        }

        return dp[ind][buy] = profit;
    }
    int stockBuySell(vector<int> arr, int n){
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,arr,dp,1,n);
    }
};

