class Solution{   
    public:
        bool solve(int x,vector<int> &arr, int index ,vector<vector<int>> &dp){
            //base cases
            if(x==0) return true;
            if(index == arr.size()) return false;
            if(dp[index][x] != -1) return dp[index][x];
            //not_take
            bool not_take = solve(x,arr,index+1,dp);
            //take
            bool take = false;
            if(x>=arr[index]){
                take = solve(x-arr[index],arr,index+1,dp);
            }
            return dp[index][x] = not_take || take;
    
        }
        bool isSubsetSum(vector<int>arr, int target){
            int n = arr.size();
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            return solve(target,arr,0,dp);
        }
    };