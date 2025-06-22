class Solution{
public:
    int func(int ind,int buy,int cap,vector<int> &arr,int n,vector<vector<vector<int>>> &dp){
        //Base case
        if(ind == n || cap == 0) return 0;

        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit = 0;
        
        if(buy){
            profit = max(-arr[ind]+func(ind+1,0,cap,arr,n,dp),func(ind+1,1,cap,arr,n,dp));
        }
        else{
           profit = max(arr[ind]+func(ind+1,1,cap-1,arr,n,dp),func(ind+1,0,cap,arr,n,dp));
        }

        return dp[ind][buy][cap] = profit;

    }
    int stockBuySell(vector<int> arr, int n, int k){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,1,k,arr,n,dp);
    }
};
