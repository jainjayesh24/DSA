class Solution {
private:
void func(int index,vector<vector<string>> &ans,vector<string> &list,string &s,int n){
    if(index==n){
        ans.push_back(list);
        return;
    }
    for(int j = index;j<=n-1;j++){
        if(check(s,index,j)){
            string substring = s.substr(index,j-index+1);
            list.push_back(substring);
            func(j+1,ans,list,s,n);
            list.pop_back();
        }
    }
}

bool check(string s,int left,int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
public:
    vector<vector<string> > partition(string s) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> list;
        int n = s.size();
        func(0,ans,list,s,n);
        return ans;
    }
};