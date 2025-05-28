class Solution{
	public:
    int modulo = 1e9+7;
    int solve(int index,vector<int> &arr,int target,vector<vector<int>> &dp){
        //Base case
        if(target==0) return 1;
        if(index == 0) return(arr[index]==target);
        //not_take
        if(dp[index][target]!=-1) return dp[index][target];
        int not_take = solve(index-1,arr,target,dp);
        //take
        int take = 0;
        if(arr[index]<=target){
            take = solve(index-1,arr,target-arr[index],dp);
        }
        return dp[index][target]=(not_take+take)%modulo;

    }
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(K+1,-1));
        return solve(n-1,arr,K,dp);
	}
};