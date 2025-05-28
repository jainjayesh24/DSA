
//Recursive 
class Solution {
    public:
        int func(int index,int prev, vector<int> &nums){
            int n = nums.size();
            //Base case
            if(index == n) return 0;
    
            //no_taken
            int len = 0 + func(index+1,prev,nums);
            //taken
            if(prev == -1 || nums[index]>nums[prev]) len = max(len, 1 + func(index+1,index,nums));
            return len;
        }
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            // vector<vector<int>> dp(n,vector<int>(n+1,-1));
            return func(0,-1,nums);
        }
    };

//Memoization

