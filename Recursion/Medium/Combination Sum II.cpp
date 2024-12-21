class Solution {
private:
void func(int index,int sum, vector<vector<int>> &ans,vector<int> &list,vector<int>& candidates,int n ){
    if(sum==0){
        ans.push_back(list);
        return;
    }
    if(sum<0 || index==n) return;
    list.push_back(candidates[index]);
    func(index+1,sum-candidates[index],ans,list,candidates,n);
    list.pop_back();
    for(int j = index+1;j<n;j++){
        if(candidates[j]!=candidates[index]){
            func(j,sum,ans,list,candidates,n);
            break;
        }
    }
}
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> list;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        func(0,target,ans,list,candidates,n);
        return ans;

    }
};