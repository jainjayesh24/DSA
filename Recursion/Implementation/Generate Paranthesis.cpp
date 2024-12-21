// Time Complexity:The time complexity is O(4^n / sqrt(n)) due to Catalan numbers counting valid parenthesis combinations.
// Space Complexity:The space complexity is O(n) for the recursive call stack and the result storage.
class Solution {
private:
void func(int open , int close,string s,vector<string>&ans,int n){
    if(open>n) return;
    if(open+close==2*n && open == close){
        ans.push_back(s);
        return;
    }
    func(open+1,close,s+"(",ans,n);
    if(open>close){
        func(open,close+1,s+")",ans,n);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string> ans;
        func(0,0,"",ans,n);
        return ans;
    }
};