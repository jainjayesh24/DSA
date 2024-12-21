// Time Complexity:O(2^n) in the worst case due to the branching of possibilities, where n is the number of candidates
// Space Complexity:O(n) for the recursion stack and additional space for storing results
class Solution {
private:
void func(int index,vector<int> &list,vector<vector<int>> &ans,vector<int> &candidates,int sum,int n){
    if(sum==0){
        ans.push_back(list);
        return;
    }
    if(sum<0 || index == n)return;
    list.push_back(candidates[index]);
    func(index,list,ans,candidates,sum-candidates[index],n);
    list.pop_back();
    func(index+1,list,ans,candidates,sum,n);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> list;
        func(0,list,ans,candidates,target,n);
        return ans;
    }
};