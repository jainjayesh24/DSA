// Time Complexity:The time complexity is O(2^n) due to the generation of all possible subsets, with n being the size of the input array.
// Space Complexity:The space complexity is O(n) for the recursion stack and for storing subsets, where n is the size of the input array.
class Solution {
private:
void func(int index,vector<vector<int>> &ans,vector<int> &list,vector<int>& nums,int n){
    if(index==n){
        ans.push_back(list);
        return;
    }
    list.push_back(nums[index]);
    func(index+1,ans,list,nums,n);
    list.pop_back();
    for(int j = index+1;j<n;j++){
        if(nums[j]!=nums[index]){
            func(j,ans,list,nums,n);
            return;
        }
    }
    func(n,ans,list,nums,n);
}
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> list;
        int n = nums.size();
        func(0,ans,list,nums,n);
        return ans;
    }
};