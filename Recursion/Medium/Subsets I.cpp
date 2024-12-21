// Time Complexity:The time complexity is O(2^n) due to the recursive calls for each element, leading to all subsets being considered.
// Space Complexity:The space complexity is O(n) for the recursion stack due to the depth of the recursive calls.
class Solution {
  private:
  void func(int index,int sum,vector<int> &nums,int n,vector<int> &ans){
    if(index==n){
      ans.push_back(sum);
      return;
    }
    func(index+1,sum+nums[index],nums,n,ans);
    func(index+1,sum,nums,n,ans);
  }
  public:
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int> ans;
        int n = nums.size();
        func(0,0,nums,n,ans);
        return ans;
    }
};