// Time Complexity:The function makes 2 recursive calls for each index, leading to a time complexity of O(2^n) due to the tree-like expansion of choices.
// Space Complexity:The space complexity is O(n) due to the recursive call stack that can go as deep as the length of the input vector.
class Solution{
    private:
    int func(int index,int sum,vector<int> &nums,int n){
        if(sum==0) return 1;
        if(sum<0 || index==n) return 0;
        int path1 = func(index+1,sum-nums[index],nums,n);
        int path2 = func(index+1,sum,nums,n);
        return path1+path2;
    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int n = nums.size();
        return func(0,k,nums,n);
    }
};