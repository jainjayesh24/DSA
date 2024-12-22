class Solution {
private:
void func(int sum,int size,vector<vector<int>> &ans,vector<int> &list){
    if(sum==0 && list.size()==size){
        ans.push_back(list);
        return;
    }
    if(sum< 0|| list.size()>size) return;
    int lastElement = list.empty()?1:list.back()+1;
    for(int i = lastElement;i<=9;i++){
        if(i<=sum){
            list.push_back(i);
            func(sum-i,size,ans,list);
            list.pop_back();
        }
        else{
            break;
        }
    }
}

public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	//your code goes here
        vector<vector<int>> ans;
        vector<int> list;
        func(n,k,ans,list);
        return ans;
    }
};