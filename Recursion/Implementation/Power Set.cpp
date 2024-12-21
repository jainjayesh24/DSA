// Time Complexity:The time complexity is O(2^n) due to generating all subsets of n elements.
// Space Complexity:The space complexity is O(n) for the recursion stack and O(2^n) for storing the subsets in the result.
class Solution {
private:
void func(int index,vector<int>&list,vector<vector<int>> &ans,vector<int> &nums,int n){
    if(index==n){
        ans.push_back(list);
        return;
    }
    list.push_back(nums[index]);
    func(index+1,list,ans,nums,n);
    list.pop_back();
    func(index+1,list,ans,nums,n);
}
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> list;
        func(0,list,ans,nums,n);
        return ans;
    }
};