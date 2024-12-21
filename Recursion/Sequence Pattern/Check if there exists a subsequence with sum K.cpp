class Solution{
    private:
    bool func(int index,int sum,vector<int>& nums,int n){
        if(sum==0) return true;
        if(sum<0 || index==n) return false;
        bool path1 = func(index+1,sum-nums[index],nums,n);
        bool path2 = func(index+1,sum,nums,n);
        return path1 || path2;
    }
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
         int n = nums.size();
         vector<int> list;
         return func(0,k,nums,n);

    }
};